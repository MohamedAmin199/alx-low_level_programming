#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <elf.h>

/**
 * main - Displays the information contained in the ELF header.
 * @argc: The number of arguments.
 * @argv: An array of pointers.
 * Return: 0
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	verify_elf_file(header->e_ident);
	printf("ELF Header:\n");
	display_magic(header->e_ident);
	display_class(header->e_ident);
	display_data(header->e_ident);
	display_version(header->e_ident);
	display_osabi(header->e_ident);
	display_abi(header->e_ident);
	display_type(header->e_type, header->e_ident);
	display_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o);
	return (0);
}


/**
 * verify_elf_file - verify if a file is an ELF file.
 * @e_ident: A pointer to an array.
 */
void verify_elf_file(unsigned char *e_ident);
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 &&
		    e_ident[i] != 'E' &&
		    e_ident[i] != 'L' &&
		    e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}


/**
 * display_magic - Display the magic numbers of an ELF header.
 * @e_ident: A pointer to an array.
 */
void display_magic(unsigned char *e_ident);
{
	int i;

	printf("  Magic Header: ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}


/**
 * display_class - Display the class of an ELF header.
 * @e_ident: A pointer to an array.
 */
void display_class(unsigned char *e_ident);
{
	printf("  Class:         ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}


/**
 * display_data - Display the data of an ELF header.
 * @e_ident: A pointer to an array.
 */
void display_data(unsigned char *e_ident);
{
	printf("  Data:         ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}


/**
 * display_version - Display the version of an ELF header.
 * @e_ident: A pointer to an array.
 */
void display_version(unsigned char *e_ident);
{
	printf("  Version:         %d",
	       e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}


/**
 * display_abi - Display the ABI of an ELF header.
 * @e_ident: A pointer to an array.
 */
void display_abi(unsigned char *e_ident);
{
	printf("  ABI Version:         %d\n",
	       e_ident[EI_ABIVERSION]);
}


/**
 * display_osabi - Display the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array.
 */
void display_osabi(unsigned char *e_ident);
{
	printf("  OS/ABI:         ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}


/**
 * display_type - Display the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array.
 */
void display_type(unsigned int e_type, unsigned char *e_ident);
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:         ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}


/**
 * display_entry - Display the entry point of an ELF header.
 * @e_entry: The address.
 * @e_ident: A pointer to an array.
 */
void display_entry(unsigned long int e_entry, unsigned char *e_ident);
{
	printf("  Entry point address:         ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}


/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor.
 */
void close_elf(int elf);
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

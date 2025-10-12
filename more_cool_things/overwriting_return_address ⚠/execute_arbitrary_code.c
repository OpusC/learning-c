#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Target function that we want to redirect execution to
void execute_whoami() {
    printf("\n=== EXPLOIT SUCCESSFUL! ===\n");
    printf("Executing whoami command:\n");
    system("whoami");
    printf("=== END OF EXPLOIT ===\n");
    exit(0);  // Exit cleanly after exploit
}

// Vulnerable function with buffer overflow
void vulnerable_function() {
    char buffer[64];  // Small buffer - easy to overflow

    printf("Enter some text (this is vulnerable to buffer overflow):\n");
    printf("Buffer address: %p\n", buffer);
    printf("vulnerable_function function address: %p\n", vulnerable_function);
    printf("execute_whoami function address: %p\n", execute_whoami);

    // UNSAFE: gets() doesn't check buffer bounds
    // This allows for buffer overflow attacks
    // gets(buffer);
    read(0, buffer, 128);

    printf("You entered: %s\n", buffer);
    printf("If you see this, the overflow didn't redirect execution\n");
}

int main() {
    printf("=== Buffer Overflow Exploit Demo ===\n");
    printf("This program demonstrates how buffer overflow can lead to arbitrary code execution\n");
    printf("WARNING: This code contains intentional vulnerabilities for educational purposes\n\n");

    printf("To exploit this:\n");
    printf("1. Compile with: gcc -fno-stack-protector -z execstack -no-pie execute_arbitrary_code.c -o exploit\n");
    printf("2. Find the offset to overwrite return address (usually 72-80 bytes for this setup)\n");
    printf("3. Create payload: python -c \"print('A'*72 + '\\x[address_bytes]')\" | ./exploit\n");
    printf("4. Replace [address_bytes] with the execute_whoami function address shown below\n\n");

    vulnerable_function();

    printf("Program completed normally (no exploit occurred)\n");
    return 0;
}

/*
EXPLOITATION NOTES:
===================

To successfully exploit this program:

1. Compile without stack protection:
   gcc -std=c99 -fno-stack-protector -z execstack -no-pie -g execute_arbitrary_code.c -o exploit

2. The vulnerable_function prints the address of execute_whoami - use this address

3. Create a payload that:
   - Fills the 64-byte buffer
   - Overwrites any padding/saved registers
   - Overwrites the return address with execute_whoami's address

4. Example exploitation:
   - Find exact offset using GDB or trial and error
   - Typical payload structure: 'A' * offset + address_bytes
   - Use little-endian format for the address

5. Modern protections that prevent this:
   - Stack canaries (detect stack corruption)
   - ASLR (randomize memory layout)
   - NX bit (prevent execution of stack data)
   - Stack protector (compiler-level protection)

This demonstrates why:
- Always use safe functions like fgets() instead of gets()
- Enable modern compiler protections in production
- Validate and sanitize all user input
- Use memory-safe languages when possible

EDUCATIONAL PURPOSE ONLY - DO NOT USE FOR MALICIOUS ACTIVITIES
*/
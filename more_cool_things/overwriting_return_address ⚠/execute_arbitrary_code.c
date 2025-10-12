/******************************************************************************
 * ⚠️⚠️⚠️ WARNING: INTENTIONALLY VULNERABLE CODE ⚠️⚠️⚠️
 *
 * This code contains DELIBERATE security vulnerabilities for educational
 * demonstration of buffer overflow exploits.
 *
 * DO NOT:
 *   - Use this code in any production environment
 *   - Compile with privileges
 *   - Execute on systems with sensitive data
 *   - Deploy on network-accessible systems
 *
 * ONLY use in isolated, sandboxed environments for learning purposes.
 ******************************************************************************/
// SAFETY: Uncomment ONLY if you understand the risks
// #define ENABLE_VULNERABLE_CODE
#ifndef ENABLE_VULNERABLE_CODE
#error "This code is intentionally vulnerable. Read the SECURITY.md file and uncomment ENABLE_VULNERABLE_CODE to compile."
#endif

#warning "Compiling intentionally vulnerable code - ensure you are in a sandboxed environment"

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
    void* return_address = __builtin_return_address(0);  // the return address of this function

    char buffer[64];  // Small buffer - easy to overflow

    printf("\033[1;31m");
    printf("╔════════════════════════════════════════════════╗\n");
    printf("║Buffer address: %p                  ║\n", buffer);
    printf("║vulnerable_function function address: %p  ║\n", vulnerable_function);
    printf("║execute_whoami function address: %p       ║\n", execute_whoami);
    printf("║function's normal return address: %p      ║\n", return_address);
    printf("╚════════════════════════════════════════════════╝\n");
    printf("\033[0m");

    printf("Enter some text (this is vulnerable to buffer overflow):\n");

    // UNSAFE: gets() doesn't check buffer bounds
    // This allows for buffer overflow attacks
    gets(buffer);

    // UNSAFE: read() with count=128 will overflow if buffer < 128 bytes
    // Unlike gets(), read() itself is safe - but misuse enables buffer overflow
    // read(0, buffer, 128);

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
// Entrada: Un entero sin signo de 32 bits
// Salida : El mismo numero pero con los bytes invertidos como si fuera una cadena
int reverse_bytes(unsigned int i) {
	return ((i >> 24) ) |
		((i >> 8) & 0xFF00) |
		((i << 8) & 0xFF0000) |
		((i << 24));
}

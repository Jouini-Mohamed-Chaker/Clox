#include <stdio.h>
#include "debug.h"
#include "value.h"

void disassembleChunk(Chunk *chunk, const char *name) {
	printf("== Disassembling Chunk: %s ==\n\n", name);
	printf("Offset    Line    Instruction    Details\n");
	printf("-----------------------------------------------------------\n");

	for (int offset = 0; offset < chunk->count; ) {
		offset = disassembleInstruction(chunk, offset);
	}
}

static int simpleInstruction(const char *name, int offset) {
	printf("%-12s\n", name);
	return offset + 1;
}

static int constantInstruction(const char *name, Chunk *chunk, int offset) {
	uint8_t constant = chunk->code[offset + 1];
	printf("%-12s Constant Index: %d, Constant Value: '", name, constant);
	printValue(chunk->constants.values[constant]);
	printf("'\n");
	return offset + 2;
}

int disassembleInstruction(Chunk *chunk, int offset) {
	printf("%06d    ", offset);

	if (offset > 0 && chunk->lines[offset] == chunk->lines[offset - 1]) {
		printf("   |    ");
	} else {
		printf("%-6d ", chunk->lines[offset]);
	}

	uint8_t instruction = chunk->code[offset];
	switch (instruction) {
		case OP_CONSTANT:
			return constantInstruction("OP_CONSTANT", chunk, offset);
		case OP_RETURN:
			return simpleInstruction("OP_RETURN", offset);
			// Add other cases here for additional instructions
		default:
			printf("Unknown Instruction: %d\n", instruction);
			return offset + 1;
	}
}



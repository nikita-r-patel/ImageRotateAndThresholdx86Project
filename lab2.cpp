// Remember to fill in your name and student ID below.
char *yourName = "Nikita Patel";
char *yourStudentID = "34811375";


// Part1) This function takes in a square sized grayscale image and applies thresholding on each pixel.
// Width and height of the image are equal to "dim".
void imageThresholding(unsigned char* image, int dim) {
	
	__asm {
		push ebx;
		push edi;
		push esi;

// YOUR CODE STARTS HERE
		
		mov ebx, image;
		mov eax, 0;
	BeginWhile:
		cmp eax, dim;
		jge EndofWhile;
		mov edx, 0;
	BeginSecondWhile:
		cmp edx, dim;
		jge EndOfInnerWhile;
		mov ecx, eax;
		imul ecx, dim;
		add ecx, edx;
		mov esi, ecx;
		mov cl, byte ptr[ebx + esi];
		shr cl, 7;
		cmp cl, 0;
		jne PixelSwap;
		mov byte ptr[ebx + esi], 0x00;
		inc edx;
		jmp BeginSecondWhile;
	PixelSwap:
		mov byte ptr[ebx + esi], 0xFF;
		inc edx;
		jmp BeginSecondWhile;
	EndOfInnerWhile:
		inc eax;
		jmp BeginWhile;
	EndofWhile:

// YOUR CODE ENDS HERE
		
		pop esi;
		pop edi;
		pop ebx;
	}
	
}


// Part2) This function rotates a given square sized color image 90 degrees clockwise.
// Width and height of the image are equal to "dim".
// Four variables are defined to simplify your implementation.
// Note that you cannot define additional variables.
void imageRotation(unsigned int* image, int dim) {
	
	unsigned int i0, i90, i180, i270;

	__asm {
		push ebx;
		push edi;
		push esi;

// YOUR CODE STARTS HERE

		mov ebx, image;
		mov eax, 0;
	BeginWhile:
		mov edx, 0;
		mov edi, dim;
		shr edi, 1;
		cmp eax, edi;
		jge EndOfWhile;
	BeginSecondWhile:
		mov ebx, image;
		mov edi, dim;
		add edi, 1;
		shr edi, 1;
		cmp edx, edi;
		jge EndOfInnerWhile;

		//first triangle
		mov ecx, eax;
		imul ecx, dim;
		add ecx, edx;
		mov esi, ecx;
		imul esi, 4;
		lea ecx, [ebx + esi];
		mov i0, ecx;

		//second triangle
		mov ecx, dim;
		sub ecx, 1;
		sub ecx, eax;
		mov esi, edx;
		imul esi, dim;
		add esi, ecx;
		imul esi, 4;
		lea ecx, [ebx + esi];
		mov i90, ecx;

		//third triangle
		mov ecx, dim;
		sub ecx, 1;
		sub ecx, eax;
		mov edi, dim;
		sub edi, 1;
		sub edi, edx;
		mov esi, ecx;
		imul esi, dim;
		add esi, edi;
		imul esi, 4;
		lea ecx, [ebx + esi];
		mov i180, ecx;

		//fourth triangle
		mov ecx, dim;
		sub ecx, 1;
		sub ecx, edx;
		mov esi, ecx;
		imul esi, dim;
		add esi, eax;
		imul esi, 4;
		lea ecx, [ebx + esi];
		mov i270, ecx;

		//rotation
		mov ecx, i0;
		mov ebx, [ecx];
		mov edi, i90;
		mov esi, [edi]; 
		mov[edi], ebx;

		mov ecx, i180;
		mov ebx, [ecx];
		mov edi, i180;
		mov ebx, [edi];
		mov[ecx], esi;

		mov ecx, i270;
		mov edi, [ecx];
		mov[ecx], ebx;

		mov ecx, i0;
		mov[ecx], edi;
	
		inc edx;
		jmp BeginSecondWhile;
		
	EndOfInnerWhile:
		inc eax;
		jmp BeginWhile;
	EndOfWhile:

// YOUR CODE ENDS HERE
	    
		pop esi;
	    pop edi;
	    pop ebx;
	}
	
}


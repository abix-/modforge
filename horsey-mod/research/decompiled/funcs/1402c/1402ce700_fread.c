// Address: 0x1402ce700
// Ghidra name: fread
// ============ 0x1402ce700 fread (size=29) ============


/* Library Function - Single Match

    fread

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



size_t __cdecl fread(void *_DstBuf,size_t _ElementSize,size_t _Count,FILE *_File)



{

  size_t sVar1;

  

  sVar1 = fread_s(_DstBuf,0xffffffffffffffff,_ElementSize,_Count,_File);

  return sVar1;

}





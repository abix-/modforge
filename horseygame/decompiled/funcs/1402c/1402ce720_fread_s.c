// Address: 0x1402ce720
// Ghidra name: fread_s
// ============ 0x1402ce720 fread_s (size=165) ============


/* Library Function - Single Match

    fread_s

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



size_t __cdecl fread_s(void *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t _Count,FILE *_File)



{

  undefined4 *puVar1;

  size_t sVar2;

  

  if ((_ElementSize != 0) && (_Count != 0)) {

    if (_File != (FILE *)0x0) {

      FUN_1402e1710(_File);

      sVar2 = FUN_1402ce494(_DstBuf,_DstSize,_ElementSize,_Count,_File);

      FUN_1402e171c(_File);

      return sVar2;

    }

    if (_DstSize != 0xffffffffffffffff) {

      FUN_1402f94c0(_DstBuf,0,_DstSize);

    }

    puVar1 = (undefined4 *)FUN_1402e68b0();

    *puVar1 = 0x16;

    FUN_1402cd454();

  }

  return 0;

}





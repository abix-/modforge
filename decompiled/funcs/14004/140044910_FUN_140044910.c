// Address: 0x140044910
// Ghidra name: FUN_140044910
// ============ 0x140044910 FUN_140044910 (size=192) ============


undefined8 FUN_140044910(undefined8 param_1,undefined8 param_2)



{

  int iVar1;

  FILE *_File;

  void *_DstBuf;

  undefined8 uVar2;

  size_t _ElementSize;

  

  _File = (FILE *)FUN_1402ce0f8(param_1,&DAT_14039be7c);

  if (_File != (FILE *)0x0) {

    FUN_1402cea4c(_File,0,2);

    iVar1 = FUN_1402cf00c(_File);

    _ElementSize = (size_t)iVar1;

    FUN_1402cea4c(_File,0,0);

    _DstBuf = (void *)_malloc_base(_ElementSize);

    fread(_DstBuf,_ElementSize,1,_File);

    FUN_1402ce288(_File);

    if (_DstBuf != (void *)0x0) {

      uVar2 = FUN_1400449e0(_DstBuf,_ElementSize,param_2);

      thunk_FUN_1402e9a80(_DstBuf);

      return uVar2;

    }

  }

  return 0;

}





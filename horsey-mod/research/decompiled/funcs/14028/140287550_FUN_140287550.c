// Address: 0x140287550
// Ghidra name: FUN_140287550
// ============ 0x140287550 FUN_140287550 (size=70) ============


bool FUN_140287550(longlong param_1,longlong param_2)



{

  void *_Buf2;

  int iVar1;

  

  _Buf2 = *(void **)(param_2 + 0x30);

  if (*(void **)(param_1 + 0x30) == (void *)0x0) {

    return _Buf2 != (void *)0x0;

  }

  if (_Buf2 != (void *)0x0) {

    iVar1 = memcmp(*(void **)(param_1 + 0x30),_Buf2,0x14);

    return iVar1 != 0;

  }

  return true;

}





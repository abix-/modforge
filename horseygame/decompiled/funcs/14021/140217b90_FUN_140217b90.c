// Address: 0x140217b90
// Ghidra name: FUN_140217b90
// ============ 0x140217b90 FUN_140217b90 (size=127) ============


longlong FUN_140217b90(undefined8 param_1)



{

  char cVar1;

  longlong lVar2;

  

  lVar2 = FUN_1401841a0(1,0x68);

  if (lVar2 != 0) {

    FUN_1402177c0(lVar2 + 0x28,0x78,8);

    FUN_1402177c0(lVar2 + 0x48,param_1,4);

    cVar1 = FUN_140217a70(lVar2 + 0x28,2);

    if (cVar1 != '\0') {

      return lVar2;

    }

    FUN_140217cf0(lVar2);

  }

  return 0;

}





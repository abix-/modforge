// Address: 0x140210ef0
// Ghidra name: FUN_140210ef0
// ============ 0x140210ef0 FUN_140210ef0 (size=221) ============


char * FUN_140210ef0(undefined4 param_1,undefined4 param_2)



{

  char *_Str1;

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  size_t sVar4;

  char *pcVar5;

  char local_28 [32];

  

  lVar2 = FUN_140142960("SDL_GAMECONTROLLERTYPE");

  if (lVar2 == 0) {

LAB_140210fb6:

    pcVar5 = (char *)0x0;

  }

  else {

    FUN_14012ef10(local_28,0x20,"0x%.4x/0x%.4x=",param_1,param_2);

    lVar3 = thunk_FUN_1402c9340(lVar2,local_28);

    if (lVar3 == 0) {

      FUN_14012ef10(local_28,0x20,"0x%.4X/0x%.4X=",param_1,param_2);

      lVar3 = thunk_FUN_1402c9340(lVar2,local_28);

      if (lVar3 == 0) goto LAB_140210fb6;

    }

    sVar4 = strlen(local_28);

    _Str1 = (char *)(sVar4 + lVar3);

    iVar1 = strncmp(_Str1,"k_eControllerType_",0x12);

    pcVar5 = _Str1 + 0x12;

    if (iVar1 != 0) {

      pcVar5 = _Str1;

    }

  }

  return pcVar5;

}





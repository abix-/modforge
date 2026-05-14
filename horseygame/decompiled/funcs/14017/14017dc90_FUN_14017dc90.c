// Address: 0x14017dc90
// Ghidra name: FUN_14017dc90
// ============ 0x14017dc90 FUN_14017dc90 (size=146) ============


undefined1 FUN_14017dc90(longlong param_1,longlong param_2,undefined4 param_3)



{

  char cVar1;

  undefined1 uVar2;

  

  cVar1 = FUN_1401489c0();

  if (cVar1 == '\0') {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","SDL_FillSurfaceRect(): dst");

    return uVar2;

  }

  if ((param_2 == 0) &&

     (((param_2 = param_1 + 100, param_2 == 0 || (*(int *)(param_1 + 0x6c) < 1)) ||

      (*(int *)(param_1 + 0x70) < 1)))) {

    return 1;

  }

  uVar2 = FUN_14017dd30(param_1,param_2,1,param_3);

  return uVar2;

}





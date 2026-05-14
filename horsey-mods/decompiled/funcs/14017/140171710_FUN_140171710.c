// Address: 0x140171710
// Ghidra name: FUN_140171710
// ============ 0x140171710 FUN_140171710 (size=261) ============


ulonglong FUN_140171710(longlong param_1,undefined8 *param_2)



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  longlong lVar4;

  char cVar5;

  int iVar6;

  ulonglong uVar7;

  undefined4 extraout_var;

  undefined8 *_Buf2;

  undefined8 local_18;

  undefined8 uStack_10;

  

  if (DAT_1403fc410 == 0) {

    uVar7 = FUN_1401730c0();

    return uVar7 & 0xffffffffffffff00;

  }

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar5 = FUN_1401aa7c0(param_1,1), cVar5 == '\0')))) {

    uVar7 = FUN_14012e850("Invalid window");

    return uVar7 & 0xffffffffffffff00;

  }

  if (*(longlong *)(DAT_1403fc410 + 0x118) == 0) {

    uVar7 = FUN_14012e850("That operation is not supported");

    return uVar7;

  }

  local_18 = 0;

  uStack_10 = 0;

  _Buf2 = &local_18;

  if (param_2 != (undefined8 *)0x0) {

    _Buf2 = param_2;

  }

  iVar6 = memcmp((void *)(param_1 + 0x150),_Buf2,0x10);

  lVar4 = DAT_1403fc410;

  if (iVar6 != 0) {

    uVar1 = *(undefined4 *)((longlong)_Buf2 + 4);

    uVar2 = *(undefined4 *)(_Buf2 + 1);

    uVar3 = *(undefined4 *)((longlong)_Buf2 + 0xc);

    *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)_Buf2;

    *(undefined4 *)(param_1 + 0x154) = uVar1;

    *(undefined4 *)(param_1 + 0x158) = uVar2;

    *(undefined4 *)(param_1 + 0x15c) = uVar3;

    uVar7 = (**(code **)(lVar4 + 0x118))(lVar4,param_1);

    return uVar7;

  }

  return CONCAT71((int7)(CONCAT44(extraout_var,iVar6) >> 8),1);

}





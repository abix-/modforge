// Address: 0x14016b720
// Ghidra name: FUN_14016b720
// ============ 0x14016b720 FUN_14016b720 (size=703) ============


void FUN_14016b720(longlong param_1)



{

  longlong lVar1;

  char cVar2;

  longlong lVar3;

  uint uVar4;

  ulonglong uVar6;

  ulonglong uVar5;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar2 = FUN_1401aa7c0(param_1,1), cVar2 != '\0')))) {

    lVar3 = *(longlong *)(param_1 + 0x1b0);

    *(undefined1 *)(param_1 + 0x10f) = 1;

    while (lVar3 != 0) {

      FUN_14016b720(lVar3);

      lVar3 = *(longlong *)(param_1 + 0x1b0);

    }

    FUN_1401cda90(param_1,0x219,0,0);

    FUN_14016b5e0(param_1);

    lVar3 = FUN_14014f110(param_1);

    if (lVar3 != 0) {

      FUN_14014da10(lVar3);

    }

    FUN_140173190(param_1,0,1);

    if ((*(uint *)(param_1 + 0x48) >> 0xb & 1) == 0) {

      FUN_14016f190(param_1);

    }

    FUN_1401747e0(*(undefined4 *)(param_1 + 0x134));

    FUN_14016b6a0(DAT_1403fc410,param_1);

    FUN_1401747e0(*(undefined4 *)(param_1 + 0x178));

    if ((*(code **)(DAT_1403fc410 + 0xb0) != (code *)0x0) &&

       ((*(uint *)(param_1 + 0x48) >> 0xc & 1) != 0)) {

      (**(code **)(DAT_1403fc410 + 0xb0))(DAT_1403fc410,param_1,0);

    }

    lVar3 = DAT_1403fc410;

    uVar5 = 0;

    uVar6 = uVar5;

    if (0 < *(int *)(DAT_1403fc410 + 0x328)) {

      do {

        lVar1 = *(longlong *)(*(longlong *)(lVar3 + 0x330) + uVar6);

        if (*(longlong *)(lVar1 + 0x68) == param_1) {

          *(undefined8 *)(lVar1 + 0x68) = 0;

        }

        uVar4 = (int)uVar5 + 1;

        uVar5 = (ulonglong)uVar4;

        uVar6 = uVar6 + 8;

      } while ((int)uVar4 < *(int *)(lVar3 + 0x328));

    }

    lVar3 = FUN_140183290();

    if (lVar3 == param_1) {

      FUN_140183d70(0);

    }

    if ((*(uint *)(param_1 + 0x48) >> 0xe & 1) != 0) {

      FUN_140162f40(1);

    }

    lVar3 = FUN_140161230();

    if (lVar3 == param_1) {

      FUN_140162ca0(0);

    }

    if (((*(byte *)(param_1 + 0x48) & 2) != 0) && (*(longlong *)(DAT_1403fc410 + 0x540) == param_1))

    {

      FUN_14016c930(param_1,0);

    }

    if (*(code **)(DAT_1403fc410 + 0x130) != (code *)0x0) {

      (**(code **)(DAT_1403fc410 + 0x130))(DAT_1403fc410,param_1);

    }

    if ((*(byte *)(param_1 + 0x48) & 2) != 0) {

      FUN_14016cef0();

    }

    if ((*(uint *)(param_1 + 0x48) >> 0x1c & 1) != 0) {

      FUN_1401741d0();

    }

    lVar3 = DAT_1403fc410;

    if (*(longlong *)(DAT_1403fc410 + 0x350) == param_1) {

      *(undefined8 *)(DAT_1403fc410 + 0x350) = 0;

    }

    if (*(longlong *)(lVar3 + 0x540) == param_1) {

      *(undefined8 *)(lVar3 + 0x540) = 0;

    }

    FUN_140138fd0(lVar3 + 800,param_1,0);

    FUN_1401aa9d0(param_1,1,0);

    FUN_1401841e0(*(undefined8 *)(param_1 + 8));

    FUN_140146010(*(undefined8 *)(param_1 + 0x10));

    FUN_140173720(param_1,0);

    if (*(longlong *)(param_1 + 0x1a0) != 0) {

      *(undefined8 *)(*(longlong *)(param_1 + 0x1a0) + 0x198) = *(undefined8 *)(param_1 + 0x198);

    }

    if (*(longlong *)(param_1 + 0x198) == 0) {

      *(undefined8 *)(DAT_1403fc410 + 0x348) = *(undefined8 *)(param_1 + 0x1a0);

    }

    else {

      *(undefined8 *)(*(longlong *)(param_1 + 0x198) + 0x1a0) = *(undefined8 *)(param_1 + 0x1a0);

    }

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x180));

    FUN_1401841e0(param_1);

    return;

  }

  FUN_14012e850("Invalid window");

  return;

}





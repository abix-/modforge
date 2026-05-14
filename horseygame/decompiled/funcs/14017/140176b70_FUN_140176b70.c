// Address: 0x140176b70
// Ghidra name: FUN_140176b70
// ============ 0x140176b70 FUN_140176b70 (size=312) ============


ulonglong FUN_140176b70(longlong param_1,int param_2,short *param_3)



{

  undefined8 *puVar1;

  longlong lVar2;

  undefined8 uVar3;

  char cVar4;

  ulonglong uVar5;

  longlong lVar6;

  

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar4 = FUN_1401aa7c0(param_1,6), cVar4 == '\0')))) {

    uVar5 = FUN_14012e850("Parameter \'%s\' is invalid","haptic");

    return uVar5 & 0xffffffffffffff00;

  }

  uVar5 = FUN_140176cb0(param_1,param_2);

  if ((char)uVar5 != '\0') {

    if (param_3 == (short *)0x0) {

      uVar5 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14030ebdc);

      return uVar5;

    }

    lVar6 = (longlong)param_2 * 0x50;

    if (*param_3 != *(short *)(lVar6 + *(longlong *)(param_1 + 0x10))) {

      uVar5 = FUN_14012e850("Haptic: Updating effect type is illegal.");

      return uVar5;

    }

    cVar4 = FUN_14021b070(param_1);

    if (cVar4 != '\0') {

      uVar5 = FUN_14021b460(param_1,param_2);

      return uVar5;

    }

    uVar5 = thunk_FUN_140288540(param_1,*(longlong *)(param_1 + 0x10) + lVar6,param_3);

    if ((char)uVar5 != '\0') {

      lVar2 = *(longlong *)(param_1 + 0x10);

      uVar3 = *(undefined8 *)(param_3 + 4);

      *(undefined8 *)(lVar2 + lVar6) = *(undefined8 *)param_3;

      ((undefined8 *)(lVar2 + lVar6))[1] = uVar3;

      uVar3 = *(undefined8 *)(param_3 + 0xc);

      puVar1 = (undefined8 *)(lVar2 + 0x10 + lVar6);

      *puVar1 = *(undefined8 *)(param_3 + 8);

      puVar1[1] = uVar3;

      uVar3 = *(undefined8 *)(param_3 + 0x14);

      puVar1 = (undefined8 *)(lVar2 + 0x20 + lVar6);

      *puVar1 = *(undefined8 *)(param_3 + 0x10);

      puVar1[1] = uVar3;

      uVar3 = *(undefined8 *)(param_3 + 0x1c);

      puVar1 = (undefined8 *)(lVar2 + 0x30 + lVar6);

      *puVar1 = *(undefined8 *)(param_3 + 0x18);

      puVar1[1] = uVar3;

      *(undefined8 *)(lVar2 + 0x40 + lVar6) = *(undefined8 *)(param_3 + 0x20);

      return CONCAT71((int7)((ulonglong)lVar2 >> 8),1);

    }

  }

  return uVar5 & 0xffffffffffffff00;

}





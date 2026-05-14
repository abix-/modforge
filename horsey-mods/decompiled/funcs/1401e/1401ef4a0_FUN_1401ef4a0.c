// Address: 0x1401ef4a0
// Ghidra name: FUN_1401ef4a0
// ============ 0x1401ef4a0 FUN_1401ef4a0 (size=863) ============


ulonglong FUN_1401ef4a0(longlong param_1,longlong param_2)



{

  undefined4 uVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  ulonglong uVar4;

  undefined8 *puVar5;

  int iVar6;

  undefined4 *puVar7;

  

  puVar2 = *(undefined4 **)(param_2 + 0x30);

  uVar1 = *(undefined4 *)(param_1 + 0x28);

  puVar3 = *(undefined4 **)(puVar2 + 0x4e);

  iVar6 = puVar3[6];

  puVar7 = *(undefined4 **)(puVar3 + 0xc);

  if (iVar6 == 2) {

    if (*(int *)(param_2 + 0x38) == 1) {

      iVar6 = 3;

    }

    else {

      if ((*(int *)(param_2 + 0x38) != 2) || (*(char *)(param_1 + 10) == '\0')) goto LAB_1401ef529;

      iVar6 = 4;

    }

LAB_1401ef525:

    puVar7 = puVar3 + 7;

  }

  else if (iVar6 == 5) {

    if ((*(int *)(param_2 + 0x38) == 2) && (*(char *)(param_1 + 10) != '\0')) {

      iVar6 = 6;

      goto LAB_1401ef525;

    }

  }

  else if (((iVar6 == 7) && (*(int *)(param_2 + 0x38) == 2)) && (*(char *)(param_1 + 10) != '\0')) {

    iVar6 = 8;

    goto LAB_1401ef525;

  }

LAB_1401ef529:

  FUN_1401ef800(param_1,param_2,iVar6,puVar7);

  if (puVar2 != *(undefined4 **)(param_1 + 0x218)) {

    if (*(char *)(puVar3 + 0x15) != '\0') {

      (**(code **)(param_1 + 0x1c0))(0x84c2);

      (**(code **)(param_1 + 0x40))(uVar1,puVar3[0x18]);

      (**(code **)(param_1 + 0x1c0))(0x84c1);

      (**(code **)(param_1 + 0x40))(uVar1,puVar3[0x16]);

    }

    if (*(char *)((longlong)puVar3 + 0x55) != '\0') {

      (**(code **)(param_1 + 0x1c0))(0x84c1);

      (**(code **)(param_1 + 0x40))(uVar1,puVar3[0x16]);

    }

    if (*(longlong *)(puVar2 + 0x38) != 0) {

      puVar7 = *(undefined4 **)(*(longlong *)(puVar2 + 0x38) + 0x10);

      (**(code **)(param_1 + 0x1c0))(0x84c1);

      (**(code **)(param_1 + 0x40))(uVar1,*puVar7);

    }

    if (*(char *)(param_1 + 0x1b8) != '\0') {

      (**(code **)(param_1 + 0x1c0))(0x84c0);

    }

    (**(code **)(param_1 + 0x40))(uVar1,*puVar3);

    *(undefined4 **)(param_1 + 0x218) = puVar2;

  }

  if (*(int *)(param_2 + 0x38) == puVar3[0x1a]) goto LAB_1401ef6d7;

  if (*(char *)(puVar3 + 0x15) == '\0') {

    if (*(char *)((longlong)puVar3 + 0x55) != '\0') goto LAB_1401ef630;

  }

  else {

    (**(code **)(param_1 + 0x1c0))(0x84c2);

    uVar4 = FUN_1401efc00(param_1,uVar1,*puVar2,*(undefined4 *)(param_2 + 0x38));

    if ((char)uVar4 == '\0') goto LAB_1401ef6b5;

LAB_1401ef630:

    (**(code **)(param_1 + 0x1c0))(0x84c1);

    uVar4 = FUN_1401efc00(param_1,uVar1,*puVar2,*(undefined4 *)(param_2 + 0x38));

    if ((char)uVar4 == '\0') goto LAB_1401ef6b5;

    (**(code **)(param_1 + 0x1c0))(0x84c0);

  }

  if (*(longlong *)(puVar2 + 0x38) != 0) {

    (**(code **)(param_1 + 0x1c0))(0x84c1);

    uVar4 = FUN_1401efc00(param_1,uVar1,0,0);

    if ((char)uVar4 == '\0') goto LAB_1401ef6b5;

    (**(code **)(param_1 + 0x1c0))(0x84c0);

  }

  uVar4 = FUN_1401efc00(param_1,uVar1,*puVar2,*(undefined4 *)(param_2 + 0x38));

  if ((char)uVar4 != '\0') {

    puVar3[0x1a] = *(undefined4 *)(param_2 + 0x38);

LAB_1401ef6d7:

    puVar5 = (undefined8 *)(param_1 + 0x1c0);

    puVar7 = (undefined4 *)(param_2 + 0x3c);

    if ((*(int *)(param_2 + 0x3c) != puVar3[0x1b]) ||

       (iVar6 = puVar3[0x1c], *(int *)(param_2 + 0x40) != iVar6)) {

      if (*(char *)(puVar3 + 0x15) == '\0') {

        if (*(char *)((longlong)puVar3 + 0x55) != '\0') {

          (*(code *)*puVar5)(0x84c1);

          FUN_1401efba0(param_1,uVar1,*puVar7,*(undefined4 *)(param_2 + 0x40));

          (*(code *)*puVar5)(0x84c0);

        }

      }

      else {

        (*(code *)*puVar5)(0x84c2);

        FUN_1401efba0(param_1,uVar1,*puVar7,*(undefined4 *)(param_2 + 0x40));

        (*(code *)*puVar5)(0x84c1);

        FUN_1401efba0(param_1,uVar1,*puVar7,*(undefined4 *)(param_2 + 0x40));

        (*(code *)*puVar5)(0x84c0);

      }

      if (*(longlong *)(puVar2 + 0x38) != 0) {

        (**(code **)(param_1 + 0x1c0))(0x84c1);

        FUN_1401efba0(param_1,uVar1,1);

        (**(code **)(param_1 + 0x1c0))(0x84c0);

      }

      FUN_1401efba0(param_1,uVar1,*(undefined4 *)(param_2 + 0x3c),*(undefined4 *)(param_2 + 0x40));

      puVar3[0x1b] = *(undefined4 *)(param_2 + 0x3c);

      iVar6 = *(int *)(param_2 + 0x40);

      puVar3[0x1c] = iVar6;

    }

    return CONCAT71((uint7)(uint3)((uint)iVar6 >> 8),1);

  }

LAB_1401ef6b5:

  return uVar4 & 0xffffffffffffff00;

}





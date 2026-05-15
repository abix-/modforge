// Address: 0x1401f4790
// Ghidra name: FUN_1401f4790
// ============ 0x1401f4790 FUN_1401f4790 (size=1055) ============


ulonglong FUN_1401f4790(longlong param_1,longlong param_2,undefined8 param_3)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  longlong lVar5;

  undefined4 *puVar6;

  undefined4 *puVar7;

  char cVar8;

  ulonglong uVar9;

  undefined8 uVar10;

  

  piVar4 = *(int **)(param_2 + 0x30);

  lVar5 = *(longlong *)(param_1 + 0x2e0);

  uVar10 = 3;

  puVar6 = *(undefined4 **)(piVar4 + 0x4e);

  iVar2 = *piVar4;

  if (*(int **)(param_1 + 0x1f0) == (int *)0x0) {

    if (iVar2 < 0x20534550) {

      if (iVar2 == 0x2053454f) {

LAB_1401f48d8:

        uVar10 = 10;

      }

      else if (iVar2 == 0x13000801) {

LAB_1401f48d0:

        uVar10 = 2;

      }

      else if (iVar2 == 0x16161804) {

LAB_1401f48c8:

        uVar10 = 5;

      }

      else {

        if (iVar2 == 0x16362004) goto LAB_1401f4830;

        if (iVar2 == 0x16561804) goto LAB_1401f4854;

        if (iVar2 != 0x16762004) goto LAB_1401f48fd;

      }

    }

    else {

LAB_1401f48e0:

      if (iVar2 == 0x3132564e) {

        uVar10 = 9;

      }

      else if (iVar2 == 0x3231564e) {

        uVar10 = 8;

      }

      else {

        if ((iVar2 != 0x32315659) && (iVar2 != 0x56555949)) {

LAB_1401f48fd:

          uVar9 = FUN_14012e850("Unsupported texture format",param_2,3,param_3);

          return uVar9;

        }

        uVar10 = 7;

      }

    }

  }

  else {

    iVar3 = **(int **)(param_1 + 0x1f0);

    if (iVar3 != iVar2) {

      if (0x2053454f < iVar2) goto LAB_1401f48e0;

      if (iVar2 == 0x2053454f) goto LAB_1401f48d8;

      if (iVar2 == 0x13000801) goto LAB_1401f48d0;

      if (iVar2 == 0x16161804) {

        if (iVar3 == 0x16362004) {

LAB_1401f4854:

          uVar10 = 6;

        }

        else {

LAB_1401f486a:

          if (iVar3 == 0x16561804) {

LAB_1401f4830:

            uVar10 = 4;

          }

          else if (iVar3 == 0x16762004) {

            uVar10 = 4;

          }

        }

      }

      else if (iVar2 == 0x16362004) {

        if (iVar3 != 0x16161804) goto LAB_1401f486a;

      }

      else if (iVar2 == 0x16561804) {

        if (iVar3 == 0x16161804) goto LAB_1401f4830;

        if (iVar3 == 0x16362004) goto LAB_1401f48c8;

        if (iVar3 == 0x16762004) goto LAB_1401f4854;

      }

      else {

        if (iVar2 != 0x16762004) goto LAB_1401f48fd;

        if ((iVar3 == 0x16161804) || (iVar3 == 0x16362004)) goto LAB_1401f4830;

      }

    }

  }

  cVar8 = FUN_1401f4bb0(lVar5,param_2,uVar10);

  if (piVar4 != *(int **)(lVar5 + 0x278)) {

    if (*(char *)(puVar6 + 9) == '\0') {

      if (*(char *)((longlong)puVar6 + 0x25) != '\0') goto LAB_1401f4974;

    }

    else {

      (**(code **)(lVar5 + 0x10))(0x84c2);

      (**(code **)(lVar5 + 0x28))(puVar6[2],puVar6[10]);

LAB_1401f4974:

      (**(code **)(lVar5 + 0x10))(0x84c1);

      (**(code **)(lVar5 + 0x28))(puVar6[2],puVar6[0xc]);

      (**(code **)(lVar5 + 0x10))(0x84c0);

    }

    if (*(longlong *)(piVar4 + 0x38) != 0) {

      puVar7 = *(undefined4 **)(*(longlong *)(piVar4 + 0x38) + 0x10);

      (**(code **)(lVar5 + 0x10))(0x84c1);

      (**(code **)(lVar5 + 0x28))(puVar6[2],*puVar7);

      (**(code **)(lVar5 + 0x10))(0x84c0);

    }

    (**(code **)(lVar5 + 0x28))(puVar6[2],*puVar6);

    *(int **)(lVar5 + 0x278) = piVar4;

  }

  if (*(int *)(param_2 + 0x38) == puVar6[0x12]) {

LAB_1401f4a98:

    piVar1 = (int *)(param_2 + 0x3c);

    if ((*piVar1 != puVar6[0x13]) || (iVar2 = puVar6[0x14], *(int *)(param_2 + 0x40) != iVar2)) {

      if (*(char *)(puVar6 + 9) == '\0') {

        if (*(char *)((longlong)puVar6 + 0x25) != '\0') {

          (**(code **)(lVar5 + 0x10))(0x84c1);

          FUN_1401f4f90(lVar5,puVar6[2],*piVar1,*(undefined4 *)(param_2 + 0x40));

          (**(code **)(lVar5 + 0x10))(0x84c0);

        }

      }

      else {

        (**(code **)(lVar5 + 0x10))(0x84c2);

        FUN_1401f4f90(lVar5,puVar6[2],*piVar1,*(undefined4 *)(param_2 + 0x40));

        (**(code **)(lVar5 + 0x10))(0x84c1);

        FUN_1401f4f90(lVar5,puVar6[2],*piVar1,*(undefined4 *)(param_2 + 0x40));

        (**(code **)(lVar5 + 0x10))(0x84c0);

      }

      if (*(longlong *)(piVar4 + 0x38) != 0) {

        (**(code **)(lVar5 + 0x10))(0x84c1);

        FUN_1401f4f90(lVar5,puVar6[2],1);

        (**(code **)(lVar5 + 0x10))(0x84c0);

      }

      FUN_1401f4f90(lVar5,puVar6[2],*(undefined4 *)(param_2 + 0x3c),*(undefined4 *)(param_2 + 0x40))

      ;

      puVar6[0x13] = *(undefined4 *)(param_2 + 0x3c);

      iVar2 = *(int *)(param_2 + 0x40);

      puVar6[0x14] = iVar2;

    }

    uVar9 = (ulonglong)CONCAT31((int3)((uint)iVar2 >> 8),cVar8 != '\0');

  }

  else {

    if (*(char *)(puVar6 + 9) == '\0') {

      if (*(char *)((longlong)puVar6 + 0x25) != '\0') goto LAB_1401f4a14;

LAB_1401f4a40:

      if (*(longlong *)(piVar4 + 0x38) != 0) {

        (**(code **)(lVar5 + 0x10))(0x84c1);

        uVar9 = FUN_1401f4ff0(lVar5,puVar6[2],0,0);

        if ((char)uVar9 == '\0') goto LAB_1401f4a8b;

        (**(code **)(lVar5 + 0x10))(0x84c0);

      }

      uVar9 = FUN_1401f4ff0(lVar5,puVar6[2],*piVar4,*(undefined4 *)(param_2 + 0x38));

      if ((char)uVar9 != '\0') {

        puVar6[0x12] = *(undefined4 *)(param_2 + 0x38);

        goto LAB_1401f4a98;

      }

    }

    else {

      (**(code **)(lVar5 + 0x10))(0x84c2);

      uVar9 = FUN_1401f4ff0(lVar5,puVar6[2],*piVar4,*(undefined4 *)(param_2 + 0x38));

      if ((char)uVar9 != '\0') {

LAB_1401f4a14:

        (**(code **)(lVar5 + 0x10))(0x84c1);

        uVar9 = FUN_1401f4ff0(lVar5,puVar6[2],*piVar4,*(undefined4 *)(param_2 + 0x38));

        if ((char)uVar9 != '\0') {

          (**(code **)(lVar5 + 0x10))(0x84c0);

          goto LAB_1401f4a40;

        }

      }

    }

LAB_1401f4a8b:

    uVar9 = uVar9 & 0xffffffffffffff00;

  }

  return uVar9;

}





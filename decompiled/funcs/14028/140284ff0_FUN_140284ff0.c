// Address: 0x140284ff0
// Ghidra name: FUN_140284ff0
// ============ 0x140284ff0 FUN_140284ff0 (size=531) ============


void FUN_140284ff0(char param_1,char param_2,longlong *param_3)



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  longlong lVar5;

  undefined2 uVar6;

  undefined2 uVar7;

  undefined2 uVar8;

  char cVar9;

  undefined8 uVar10;

  undefined4 *puVar11;

  longlong lVar12;

  undefined4 *puVar13;

  longlong lVar14;

  undefined2 local_res18 [4];

  undefined2 local_res20 [4];

  undefined2 local_58 [4];

  undefined1 local_50 [24];

  

  lVar12 = *param_3;

  lVar14 = 0;

  local_58[0] = 0;

  local_res20[0] = 0;

  local_res18[0] = 0;

  cVar9 = FUN_14020a870();

  if ((cVar9 == '\0') && (param_2 != '\0')) {

    while (lVar5 = lVar12, lVar5 != 0) {

      if (((*(char *)(lVar5 + 0x20) != '\0') && (*(char *)(lVar5 + 0x22) == param_1)) &&

         (*(char *)(lVar5 + 0x21) == param_2)) {

        if (lVar5 == *param_3) {

          *param_3 = *(longlong *)(lVar5 + 0x578);

        }

        else if (lVar14 != 0) {

          *(undefined8 *)(lVar14 + 0x578) = *(undefined8 *)(lVar5 + 0x578);

        }

        *(longlong *)(lVar5 + 0x578) = DAT_1403ffc48;

        DAT_1403ffc48 = lVar5;

        return;

      }

      lVar14 = lVar5;

      lVar12 = *(longlong *)(lVar5 + 0x578);

    }

    uVar10 = FUN_1402852d0(param_1,param_2);

    FUN_140285210(param_1,local_58,local_res20,local_res18);

    uVar8 = local_58[0];

    uVar7 = local_res20[0];

    uVar6 = local_res18[0];

    cVar9 = FUN_14015ba80(local_58[0],local_res20[0],local_res18[0],uVar10);

    if (((cVar9 == '\0') &&

        (cVar9 = FUN_1401599b0(&PTR_FUN_1403e50f0,uVar8,uVar7,uVar6,uVar10), cVar9 == '\0')) &&

       (puVar11 = (undefined4 *)FUN_1401841a0(1,0x580), puVar11 != (undefined4 *)0x0)) {

      *(undefined1 *)(puVar11 + 8) = 1;

      lVar12 = FUN_1401578c0(uVar8,uVar7,0,uVar10);

      *(longlong *)(puVar11 + 4) = lVar12;

      if (lVar12 == 0) {

        FUN_1401841e0(puVar11);

      }

      else {

        FUN_14012ef10(puVar11 + 0x11c,0x104,"XInput#%u",param_1);

        puVar13 = (undefined4 *)FUN_140157780(local_50,3,uVar8,uVar7,uVar6,0,uVar10,0x78,param_2);

        uVar1 = *puVar13;

        uVar2 = puVar13[1];

        uVar3 = puVar13[2];

        uVar4 = puVar13[3];

        *(char *)((longlong)puVar11 + 0x21) = param_2;

        *(char *)((longlong)puVar11 + 0x22) = param_1;

        *puVar11 = uVar1;

        puVar11[1] = uVar2;

        puVar11[2] = uVar3;

        puVar11[3] = uVar4;

        FUN_14020f660(puVar11);

      }

    }

  }

  return;

}





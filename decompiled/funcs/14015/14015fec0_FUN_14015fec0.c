// Address: 0x14015fec0
// Ghidra name: FUN_14015fec0
// ============ 0x14015fec0 FUN_14015fec0 (size=440) ============


void FUN_14015fec0(longlong param_1)



{

  undefined8 *puVar1;

  char cVar2;

  undefined4 uVar3;

  longlong lVar4;

  bool bVar5;

  float fVar6;

  char cVar7;

  undefined8 uVar8;

  undefined8 *puVar9;

  longlong lVar10;

  longlong lVar11;

  undefined4 uVar12;

  undefined4 uVar13;

  undefined4 uVar14;

  undefined8 local_58;

  

  if (param_1 != 0) {

    uVar8 = 0x8120;

    uVar3 = *(undefined4 *)(param_1 + 0x68);

    cVar2 = *(char *)(param_1 + 0x94);

    local_58 = *(undefined8 *)(param_1 + 0x60);

    uVar12 = (undefined4)local_58;

    uVar14 = (undefined4)((ulonglong)local_58 >> 0x20);

    uVar13 = uVar12;

    if (cVar2 == '\0') {

      cVar7 = FUN_14015c2a0();

      *(char *)(param_1 + 0x95) = cVar7;

      if (cVar7 == '\0') {

        uVar13 = (undefined4)uVar8;

      }

      local_58 = CONCAT44(uVar14,uVar13);

    }

    fVar6 = DAT_14039ca44;

    for (lVar4 = *(longlong *)(param_1 + 0xd0); lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 0x38)) {

      if (cVar2 != '\0') {

        if ((*(longlong *)(lVar4 + 0x28) == 0) && (*(float *)(lVar4 + 0x14) == fVar6)) {

          bVar5 = false;

        }

        else {

          bVar5 = true;

        }

        uVar13 = uVar12;

        if (bVar5) {

          uVar13 = (undefined4)uVar8;

        }

        local_58._4_4_ = (undefined4)((ulonglong)local_58 >> 0x20);

        local_58 = CONCAT44(local_58._4_4_,uVar13);

        uVar14 = local_58._4_4_;

      }

      puVar9 = *(undefined8 **)(lVar4 + 0x18);

      if (puVar9 != (undefined8 *)0x0) {

        lVar11 = 0x30;

        if (cVar2 == '\0') {

          lVar11 = 0x3c;

        }

        do {

          puVar1 = (undefined8 *)(lVar11 + (longlong)puVar9);

          FUN_140179b40(*puVar9);

          *puVar1 = CONCAT44(uVar14,uVar13);

          *(undefined4 *)(puVar1 + 1) = uVar3;

          lVar10 = 0x48;

          if (cVar2 == '\0') {

            lVar10 = 0x50;

          }

          FUN_140168720(puVar9,puVar1,lVar10 + (longlong)puVar9,*(undefined8 *)(param_1 + 0x70),

                        *(undefined4 *)(param_1 + 100),0xffffffff);

          FUN_140179b60(*puVar9);

          puVar9 = (undefined8 *)puVar9[0x19];

        } while (puVar9 != (undefined8 *)0x0);

        uVar8 = 0x8120;

      }

    }

  }

  return;

}





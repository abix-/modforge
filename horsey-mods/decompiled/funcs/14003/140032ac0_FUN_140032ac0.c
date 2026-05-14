// Address: 0x140032ac0
// Ghidra name: FUN_140032ac0
// ============ 0x140032ac0 FUN_140032ac0 (size=1214) ============


void FUN_140032ac0(longlong param_1)



{

  longlong *plVar1;

  float fVar2;

  float fVar3;

  ulonglong uVar4;

  undefined8 uVar5;

  longlong lVar6;

  longlong lVar7;

  ulonglong uVar8;

  int iVar9;

  ulonglong uVar10;

  ulonglong uVar11;

  uint uVar12;

  ulonglong uVar13;

  longlong *plVar14;

  undefined4 uVar15;

  undefined4 local_res8;

  undefined4 uStackX_c;

  undefined8 local_res10;

  char acStackY_4c8 [96];

  

  uVar8 = 0;

  lVar6 = *(longlong *)(param_1 + 0x2a0);

  uVar4 = uVar8;

  uVar13 = uVar8;

  if (*(longlong *)(param_1 + 0x2a8) - lVar6 >> 4 != 0) {

    do {

      if (*(char *)(*(longlong *)

                     (*(longlong *)(param_1 + 0x260) + (longlong)*(int *)(lVar6 + uVar4) * 8) + 0x21

                   ) != '\0') {

        lVar7 = *(longlong *)(param_1 + 600);

        if (lVar7 != 0) {

          FUN_140005cf0(lVar7);

          FUN_1402c7088(lVar7,0x19380);

          lVar6 = *(longlong *)(param_1 + 0x2a0);

        }

        *(undefined8 *)(param_1 + 600) = 0;

      }

      uVar12 = (int)uVar13 + 1;

      uVar4 = uVar4 + 0x10;

      uVar13 = (ulonglong)uVar12;

    } while ((ulonglong)(longlong)(int)uVar12 <

             (ulonglong)(*(longlong *)(param_1 + 0x2a8) - lVar6 >> 4));

  }

  fVar3 = DAT_140303758;

  fVar2 = DAT_14030335c;

  if (*(longlong *)(param_1 + 600) == 0) {

    FUN_1400c4320("creating world");

    local_res10 = FUN_1402c704c(0x19380);

    uVar4 = uVar8;

    if (local_res10 != 0) {

      local_res8 = 0;

      uStackX_c = 0x41200000;

      uVar4 = FUN_140005a10(local_res10,&local_res8,1);

    }

    *(ulonglong *)(param_1 + 600) = uVar4;

    FUN_140005e00(uVar4,param_1);

    uVar15 = DAT_14039ca44;

    local_res10 = 0xc1200000;

    local_res8 = 0x42340000;

    uStackX_c = 0x3f800000;

    iVar9 = 1;

    lVar6 = 4;

    do {

      local_res10 = CONCAT44(((float)iVar9 * fVar3 * fVar2) / *(float *)(param_1 + 0x114),

                             (undefined4)local_res10);

      uVar5 = FUN_1400833d0(*(undefined8 *)(param_1 + 600),local_res10,1);

      FUN_140083480(uVar5,DAT_1403ffbe8,0x3f80000042340000,0,0,uVar15,0);

      FUN_140084570(uVar5,iVar9,1);

      iVar9 = iVar9 + 1;

      lVar6 = lVar6 + -1;

    } while (lVar6 != 0);

  }

  if (*(int *)(param_1 + 0x278) == 0) {

    *(undefined4 *)(param_1 + 0x294) = 0xffffff10;

    FUN_1402f94c0(&stack0xfffffffffffffbb8,0,0x3c0);

    lVar6 = *(longlong *)(param_1 + 0x260);

    uVar4 = uVar8;

    uVar13 = uVar8;

    uVar11 = uVar8;

    uVar10 = uVar8;

    if (*(longlong *)(param_1 + 0x268) - lVar6 >> 3 != 0) {

      do {

        do {

          lVar7 = (longlong)*(char *)(*(longlong *)(uVar11 + lVar6) + uVar10 + 0x2b8 + uVar4) +

                  -0x448;

          if ((&stack0xfffffffffffffbb8)[uVar4 * 4 + lVar7 + 0x448] == '\0') {

            (&stack0xfffffffffffffbb8)[uVar4 * 4 + lVar7 + 0x448] = 1;

            *(int *)(param_1 + 0x294) = *(int *)(param_1 + 0x294) + 1;

          }

          uVar4 = uVar4 + 1;

        } while (((longlong)uVar4 < 0xf0) ||

                (uVar10 = uVar10 + 0xf0, uVar4 = uVar8, (longlong)uVar10 < 0x1e0));

        uVar12 = (int)uVar13 + 1;

        uVar13 = (ulonglong)uVar12;

        uVar11 = uVar11 + 8;

        uVar10 = uVar8;

      } while ((ulonglong)(longlong)(int)uVar12 <

               (ulonglong)(*(longlong *)(param_1 + 0x268) - lVar6 >> 3));

    }

    if (*(int *)(param_1 + 0x288) == 0) {

      *(undefined4 *)(param_1 + 0x290) = *(undefined4 *)(param_1 + 0x294);

    }

  }

  plVar1 = (longlong *)(param_1 + 0x2a0);

  lVar6 = *plVar1;

  lVar7 = *(longlong *)(param_1 + 0x2a8);

  uVar4 = lVar7 - lVar6 >> 4;

  if (uVar4 < 5) {

    if (uVar4 < 4) {

      if ((ulonglong)(*(longlong *)(param_1 + 0x2b0) - lVar6 >> 4) < 4) {

        FUN_140036bb0(plVar1,4,&local_res8);

      }

      else {

        if (4 - uVar4 != 0) {

          lVar6 = (4 - uVar4) * 0x10;

          FUN_1402f94c0(lVar7,0,lVar6);

          lVar7 = lVar7 + lVar6;

        }

        *(longlong *)(param_1 + 0x2a8) = lVar7;

      }

    }

  }

  else {

    *(longlong *)(param_1 + 0x2a8) = lVar6 + 0x40;

  }

  plVar14 = (longlong *)(param_1 + 0x2a0);

  lVar6 = *plVar1;

  uVar4 = uVar8;

  if (*(longlong *)(param_1 + 0x2a8) - lVar6 >> 4 != 0) {

    do {

      iVar9 = *(int *)(param_1 + 0x278) * 4 + (int)uVar8;

      *(int *)(lVar6 + uVar4) = iVar9;

      *(undefined4 *)(*plVar14 + 4 + uVar4) = 0;

      *(undefined4 *)(*plVar14 + 0xc + uVar4) = 0;

      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x260) + (longlong)iVar9 * 8);

      uVar12 = (int)uVar8 + 1;

      uVar8 = (ulonglong)uVar12;

      FUN_1400b6820(lVar6,0,((float)(int)uVar12 * fVar3 * fVar2) / *(float *)(param_1 + 0x114));

      FUN_1400b3dc0(lVar6,*(undefined8 *)(param_1 + 600));

      FUN_1400b6990(lVar6,uVar12,0);

      *(undefined2 *)(lVar6 + 0x205) = 0;

      *(undefined4 *)(lVar6 + 0x268) = 0x3f800000;

      *(undefined4 *)(lVar6 + 0x26c) = 0x3f800000;

      lVar7 = *plVar14;

      uVar15 = FUN_1400b5fe0(lVar6);

      *(undefined4 *)(lVar7 + 8 + uVar4) = uVar15;

      lVar6 = *plVar14;

      uVar4 = uVar4 + 0x10;

    } while ((ulonglong)(longlong)(int)uVar12 <

             (ulonglong)(*(longlong *)(param_1 + 0x2a8) - lVar6 >> 4));

  }

  *(undefined8 *)(param_1 + 0x27c) = 2;

  return;

}





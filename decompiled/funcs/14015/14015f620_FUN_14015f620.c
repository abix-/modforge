// Address: 0x14015f620
// Ghidra name: FUN_14015f620
// ============ 0x14015f620 FUN_14015f620 (size=717) ============


undefined8 FUN_14015f620(undefined8 *param_1)



{

  longlong lVar1;

  longlong lVar2;

  ulonglong uVar3;

  bool bVar4;

  float fVar5;

  char cVar6;

  int iVar7;

  uint uVar8;

  undefined8 uVar9;

  ulonglong uVar10;

  undefined8 uVar11;

  undefined8 uVar12;

  undefined4 uVar13;

  undefined8 uVar14;

  undefined8 uVar15;

  undefined4 uVar16;

  undefined8 local_48;

  undefined4 local_40;

  

  FUN_140179b40(*param_1);

  iVar7 = FUN_140138fe0((longlong)param_1 + 0x8c);

  if (iVar7 != 0) {

    FUN_140179b60(*param_1);

    return 0;

  }

  bVar4 = false;

  if (param_1[0x1a] == 0) {

    (*(code *)param_1[8])();

    FUN_140179b60(*param_1);

    return 1;

  }

  uVar8 = (*(code *)param_1[7])(param_1,param_1[0x13],*(undefined4 *)((longlong)param_1 + 0x6c));

  fVar5 = DAT_14039ca44;

  uVar10 = (ulonglong)uVar8;

  if ((int)uVar8 < 0) {

    FUN_140179b60(*param_1);

  }

  else {

    if (0 < (int)uVar8) {

      bVar4 = false;

      for (lVar1 = param_1[0x1a]; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x38)) {

        iVar7 = FUN_140138fe0(lVar1 + 0x10);

        if (iVar7 == 0) {

          uVar11 = param_1[0x13];

          if ((*(longlong *)(lVar1 + 0x28) != 0) || (*(float *)(lVar1 + 0x14) != fVar5)) {

            local_40 = *(undefined4 *)(param_1 + 0xd);

            uVar11 = param_1[0x15];

            local_48._4_4_ = (int)((ulonglong)param_1[0xc] >> 0x20);

            uVar16 = *(undefined4 *)(lVar1 + 0x14);

            uVar3 = uVar10 / ((*(uint *)(param_1 + 0xc) >> 3 & 0x1f) *

                             *(int *)((longlong)param_1 + 100));

            uVar15 = 0;

            uVar14 = 0;

            uVar13 = 0x8120;

            local_48 = CONCAT44(local_48._4_4_,0x8120);

            uVar12 = 0;

            uVar10 = (ulonglong)(uint)((int)uVar3 * local_48._4_4_ * 4);

            uVar9 = uVar11;

            iVar7 = local_48._4_4_;

            FUN_140163e70(uVar3);

            if (*(code **)(lVar1 + 0x28) != (code *)0x0) {

              (**(code **)(lVar1 + 0x28))

                        (*(undefined8 *)(lVar1 + 0x30),&local_48,param_1[0x15],uVar10,uVar12,uVar9,

                         uVar13,iVar7,uVar14,uVar15,uVar16);

            }

          }

          for (lVar2 = *(longlong *)(lVar1 + 0x18); lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 200))

          {

            cVar6 = FUN_14015d510(*(undefined4 *)((longlong)param_1 + 100),

                                  *(undefined8 *)(lVar2 + 0x48),param_1[0xe]);

            uVar9 = uVar11;

            if (cVar6 == '\0') {

              uVar8 = *(uint *)(param_1 + 0xc);

              iVar7 = *(int *)((longlong)param_1 + 100);

              uVar9 = param_1[0x14];

              FUN_140163e70(uVar10 / ((uVar8 >> 3 & 0x1f) * iVar7),uVar11,uVar8,iVar7,0,uVar9,uVar8,

                            iVar7,*(undefined8 *)(lVar2 + 0x48),0,fVar5);

            }

            cVar6 = FUN_140167f30(lVar2,uVar9,uVar10);

            if (cVar6 == '\0') {

              bVar4 = true;

              break;

            }

          }

        }

      }

    }

    FUN_140179b60(*param_1);

    if (!bVar4) {

      return 1;

    }

  }

  FUN_14015d5d0(param_1);

  return 1;

}





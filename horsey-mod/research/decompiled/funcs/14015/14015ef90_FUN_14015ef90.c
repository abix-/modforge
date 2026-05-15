// Address: 0x14015ef90
// Ghidra name: FUN_14015ef90
// ============ 0x14015ef90 FUN_14015ef90 (size=1155) ============


undefined8 FUN_14015ef90(undefined8 *param_1)



{

  uint uVar1;

  uint uVar2;

  longlong lVar3;

  code *pcVar4;

  longlong lVar5;

  bool bVar6;

  bool bVar7;

  undefined4 uVar8;

  char cVar9;

  int iVar10;

  uint uVar11;

  int iVar12;

  uint uVar13;

  longlong lVar14;

  longlong lVar15;

  longlong lVar16;

  undefined8 local_70;

  undefined4 local_68;

  

  FUN_140179b40(*param_1);

  iVar10 = FUN_140138fe0((longlong)param_1 + 0x8c);

  if (iVar10 != 0) {

    FUN_140179b60(*param_1);

    return 0;

  }

  uVar1 = *(uint *)((longlong)param_1 + 0x6c);

  bVar6 = false;

  bVar7 = false;

  lVar14 = (*(code *)param_1[5])(param_1);

  if (uVar1 == 0) {

LAB_14015f141:

    FUN_140179b60(*param_1);

    if (!bVar6) {

      return 1;

    }

  }

  else {

    if (lVar14 != 0) {

      if (*(char *)((longlong)param_1 + 0x95) == '\0') {

        lVar15 = lVar14;

        if (*(uint *)(param_1 + 0xc) != 0x8120) {

          lVar15 = param_1[0x14];

        }

        uVar11 = uVar1 / (*(uint *)(param_1 + 0xc) >> 3 & 0x1f);

        local_70 = CONCAT44((int)((ulonglong)param_1[0xc] >> 0x20),0x8120);

        iVar10 = uVar11 * 4;

        local_68 = *(undefined4 *)(param_1 + 0xd);

        FUN_1402f94c0(lVar15,0,(longlong)iVar10);

        uVar8 = DAT_14039ca44;

        for (lVar3 = param_1[0x1a]; lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 0x38)) {

          iVar12 = FUN_140138fe0(lVar3 + 0x10);

          if (iVar12 == 0) {

            pcVar4 = *(code **)(lVar3 + 0x28);

            lVar16 = lVar15;

            if (pcVar4 != (code *)0x0) {

              lVar16 = param_1[0x15];

              FUN_1402f94c0(lVar16,0,(longlong)iVar10);

            }

            for (lVar5 = *(longlong *)(lVar3 + 0x18); bVar6 = bVar7, lVar5 != 0;

                lVar5 = *(longlong *)(lVar5 + 200)) {

              uVar13 = FUN_140167840(lVar5,param_1[0x13],iVar10,*(undefined4 *)(lVar3 + 0x14));

              if ((int)uVar13 < 0) {

                bVar6 = true;

                break;

              }

              if (0 < (int)uVar13) {

                cVar9 = FUN_14015d510(*(undefined4 *)((longlong)param_1 + 100),

                                      *(undefined8 *)(lVar5 + 0x50),param_1[0xe]);

                if (cVar9 == '\0') {

                  uVar2 = *(uint *)(param_1 + 0xc);

                  iVar12 = *(int *)((longlong)param_1 + 100);

                  FUN_140163e70((ulonglong)uVar13 / (ulonglong)((uVar2 >> 3 & 0x1f) * iVar12),

                                param_1[0x13],uVar2,iVar12,0,param_1[0x13],uVar2,iVar12,param_1[0xe]

                                ,0,uVar8);

                }

                FUN_14015caf0(lVar16,param_1[0x13],(ulonglong)uVar13);

              }

            }

            bVar7 = bVar6;

            if (pcVar4 != (code *)0x0) {

              (*pcVar4)(*(undefined8 *)(lVar3 + 0x30),&local_70,lVar16,iVar10);

              FUN_14015caf0(lVar15,lVar16,iVar10);

            }

          }

        }

        if (lVar15 != lVar14) {

          iVar10 = *(int *)((longlong)param_1 + 100);

          FUN_140163e70((longlong)(int)uVar11 / (longlong)iVar10 & 0xffffffff,lVar15,0x8120,iVar10,0

                        ,param_1[0x13],*(undefined4 *)(param_1 + 0xc),iVar10,0,0,uVar8);

          FUN_1402f8e20(lVar14,param_1[0x13],(longlong)(int)uVar1);

        }

      }

      else {

        lVar15 = param_1[0x1a];

        lVar3 = *(longlong *)(lVar15 + 0x18);

        iVar10 = FUN_140138fe0(lVar15 + 0x10);

        if (iVar10 == 0) {

          uVar11 = FUN_140167840(lVar3,lVar14,uVar1,*(undefined4 *)(lVar15 + 0x14));

          if ((int)uVar11 < 0) {

            bVar6 = true;

            FUN_1402f94c0(lVar14,*(undefined4 *)(param_1 + 0x11),(longlong)(int)uVar1);

            goto LAB_14015f105;

          }

        }

        else {

          uVar11 = 0;

        }

        if ((int)uVar11 < (int)uVar1) {

          FUN_1402f94c0((ulonglong)uVar11 + lVar14,*(undefined4 *)(param_1 + 0x11),

                        (longlong)(int)(uVar1 - uVar11));

        }

        if ((uVar11 != 0) &&

           (cVar9 = FUN_14015d510(*(undefined4 *)((longlong)param_1 + 100),

                                  *(undefined8 *)(lVar3 + 0x50),param_1[0xe]), cVar9 == '\0')) {

          uVar13 = *(uint *)(param_1 + 0xc);

          iVar10 = *(int *)((longlong)param_1 + 100);

          FUN_140163e70((ulonglong)uVar11 / (ulonglong)((uVar13 >> 3 & 0x1f) * iVar10),lVar14,uVar13

                        ,iVar10,0,lVar14,uVar13,iVar10,param_1[0xe],0,DAT_14039ca44);

        }

        bVar6 = false;

      }

LAB_14015f105:

      cVar9 = (*(code *)param_1[4])(param_1,lVar14,uVar1);

      if (cVar9 != '\0') goto LAB_14015f141;

    }

    FUN_140179b60(*param_1);

  }

  FUN_14015d5d0(param_1);

  return 1;

}





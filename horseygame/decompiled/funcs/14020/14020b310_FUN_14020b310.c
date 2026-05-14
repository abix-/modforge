// Address: 0x14020b310
// Ghidra name: FUN_14020b310
// ============ 0x14020b310 FUN_14020b310 (size=656) ============


undefined8 FUN_14020b310(void)



{

  int iVar1;

  ulonglong uVar2;

  undefined8 *puVar3;

  longlong *plVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  longlong lVar7;

  uint uVar8;

  uint local_res8 [2];

  longlong *local_res10;

  longlong *local_res18 [2];

  

  if ((DAT_1403fd248 != (longlong *)0x0) && (DAT_1403fd23d != '\0')) {

    uVar6 = 0;

    DAT_1403fd23d = '\0';

    if (DAT_1403fd23e != '\0') {

      DAT_1403fd23e = '\0';

      uVar5 = uVar6;

      uVar2 = uVar6;

      if (0 < DAT_1403fd238) {

        do {

          uVar8 = (int)uVar2 + 1;

          *(undefined1 *)(*(longlong *)(uVar5 + (longlong)DAT_1403fd230) + 0x51) = 0;

          uVar5 = uVar5 + 8;

          uVar2 = (ulonglong)uVar8;

        } while ((int)uVar8 < DAT_1403fd238);

      }

      iVar1 = (**(code **)(*DAT_1403fd248 + 0x50))(DAT_1403fd248,local_res18);

      if (-1 < iVar1) {

        iVar1 = (**(code **)(*local_res18[0] + 0x38))(local_res18[0],local_res8);

        if (-1 < iVar1) {

          uVar5 = uVar6;

          if (local_res8[0] != 0) {

            do {

              iVar1 = (**(code **)(*local_res18[0] + 0x30))(local_res18[0],uVar5,&local_res10);

              if (-1 < iVar1) {

                uVar2 = uVar6;

                plVar4 = DAT_1403fd230;

                if (0 < DAT_1403fd238) {

                  do {

                    if (*(longlong **)*plVar4 == local_res10) {

                      *(undefined1 *)((longlong)*plVar4 + 0x51) = 1;

                      (**(code **)(*local_res10 + 0x10))();

                      goto LAB_14020b48f;

                    }

                    uVar8 = (int)uVar2 + 1;

                    uVar2 = (ulonglong)uVar8;

                    plVar4 = plVar4 + 1;

                  } while ((int)uVar8 < DAT_1403fd238);

                }

                puVar3 = (undefined8 *)FUN_1401841a0(1,0x58);

                if (puVar3 == (undefined8 *)0x0) {

                  return 0;

                }

                plVar4 = (longlong *)FUN_140184230(DAT_1403fd230,(longlong)(DAT_1403fd238 + 1) << 3)

                ;

                if (plVar4 == (longlong *)0x0) {

                  FUN_1401841e0(puVar3);

                  return 0;

                }

                DAT_1403fd238 = DAT_1403fd238 + 1;

                DAT_1403fd230 = plVar4;

                plVar4[(longlong)DAT_1403fd238 + -1] = (longlong)puVar3;

                *puVar3 = local_res10;

                *(undefined1 *)((longlong)puVar3 + 0x51) = 1;

              }

LAB_14020b48f:

              uVar8 = (int)uVar5 + 1;

              uVar5 = (ulonglong)uVar8;

            } while (uVar8 < local_res8[0]);

          }

          lVar7 = (longlong)(DAT_1403fd238 + -1);

          if (-1 < DAT_1403fd238 + -1) {

            do {

              puVar3 = (undefined8 *)DAT_1403fd230[lVar7];

              if (*(char *)((longlong)puVar3 + 0x51) == '\0') {

                if (puVar3[9] != 0) {

                  *(undefined1 *)(puVar3[9] + 0x56) = 0;

                  *(undefined8 *)(puVar3[9] + 0x60) = 0;

                }

                (**(code **)(*(longlong *)*puVar3 + 0x10))();

                FUN_1401841e0(puVar3);

                DAT_1403fd230[lVar7] = DAT_1403fd230[DAT_1403fd238 + -1];

                DAT_1403fd238 = DAT_1403fd238 + -1;

              }

              lVar7 = lVar7 + -1;

            } while (-1 < lVar7);

          }

        }

        (**(code **)(*local_res18[0] + 0x10))();

      }

    }

    uVar5 = uVar6;

    if (0 < DAT_1403fd238) {

      do {

        plVar4 = (longlong *)**(undefined8 **)(uVar5 + (longlong)DAT_1403fd230);

        iVar1 = (**(code **)(*plVar4 + 0x40))

                          (plVar4,*(undefined8 **)(uVar5 + (longlong)DAT_1403fd230) + 1);

        if (iVar1 < 0) {

          *(undefined1 *)(*(longlong *)(uVar5 + (longlong)DAT_1403fd230) + 0x51) = 0;

        }

        uVar8 = (int)uVar6 + 1;

        uVar6 = (ulonglong)uVar8;

        uVar5 = uVar5 + 8;

      } while ((int)uVar8 < DAT_1403fd238);

    }

  }

  return 1;

}





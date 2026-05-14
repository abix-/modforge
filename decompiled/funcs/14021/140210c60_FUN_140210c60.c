// Address: 0x140210c60
// Ghidra name: FUN_140210c60
// ============ 0x140210c60 FUN_140210c60 (size=647) ============


undefined8 FUN_140210c60(void)



{

  char cVar1;

  undefined2 uVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  ulonglong uVar6;

  longlong lVar7;

  char *pcVar8;

  undefined1 *puVar9;

  char *pcVar10;

  char *_Str1;

  char *pcVar11;

  int local_res8 [2];

  longlong local_res10;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  

  _guard_check_icall();

  if ((DAT_1403fd3c8 != 0) &&

     ((((uVar6 = FUN_140149350(), DAT_1403fd3d8 == 0 || (DAT_1403fd3d8 + 3000 <= uVar6)) &&

       (DAT_1403fd3d8 = uVar6, lVar7 = FUN_140210a10(DAT_1403fd3c8), lVar7 != 0)) &&

      (lVar7 != DAT_1403fd3d0)))) {

    pcVar8 = (char *)FUN_14012c650(DAT_1403fd3c8,&local_res10);

    if (pcVar8 != (char *)0x0) {

      FUN_140210ad0();

      pcVar11 = pcVar8 + local_res10;

      local_38 = 0;

      iVar4 = -1;

      local_48 = 0;

      uStack_40 = 0;

      pcVar10 = pcVar8;

      if (pcVar8 < pcVar11) {

LAB_140210d32:

        do {

          cVar1 = *pcVar10;

          if (((cVar1 == '\0') || (cVar1 == '\r')) || (_Str1 = pcVar10, cVar1 == '\n')) {

            pcVar10 = pcVar10 + 1;

            _Str1 = pcVar10;

            if (pcVar10 < pcVar11) goto LAB_140210d32;

          }

          for (; ((pcVar10 < pcVar11 && (*pcVar10 != '\r')) && (*pcVar10 != '\n'));

              pcVar10 = pcVar10 + 1) {

          }

          *pcVar10 = '\0';

          iVar3 = FUN_14012ef30(_Str1,"[slot %d]",local_res8);

          if (iVar3 == 1) {

            iVar3 = local_res8[0];

            if (-1 < iVar4) {

              FUN_140210920(iVar4,&local_48);

              iVar3 = local_res8[0];

            }

          }

          else {

            puVar9 = (undefined1 *)thunk_FUN_1402c9190(_Str1,0x3d);

            iVar3 = iVar4;

            if (puVar9 != (undefined1 *)0x0) {

              *puVar9 = 0;

              puVar9 = puVar9 + 1;

              iVar4 = strcmp(_Str1,"name");

              if (iVar4 == 0) {

                FUN_1401841e0(uStack_40);

                uStack_40 = FUN_14012f0d0(puVar9);

              }

              else {

                iVar4 = strcmp(_Str1,"VID");

                if (iVar4 == 0) {

                  uVar2 = thunk_FUN_1402d8bf4(puVar9,0,0);

                  local_38 = CONCAT62(local_38._2_6_,uVar2);

                }

                else {

                  iVar4 = strcmp(_Str1,"PID");

                  if (iVar4 == 0) {

                    uVar2 = thunk_FUN_1402d8bf4(puVar9,0,0);

                    local_38._0_4_ = CONCAT22(uVar2,(undefined2)local_38);

                  }

                  else {

                    iVar4 = strcmp(_Str1,"type");

                    if (iVar4 == 0) {

                      uVar5 = FUN_14013f0c0(puVar9);

                      local_38 = CONCAT44(uVar5,(undefined4)local_38);

                    }

                    else {

                      iVar4 = strcmp(_Str1,"handle");

                      if (iVar4 == 0) {

                        local_48 = thunk_FUN_1402d8ca8(puVar9,0,0);

                      }

                    }

                  }

                }

              }

            }

          }

          iVar4 = iVar3;

        } while (pcVar10 < pcVar11);

        if (-1 < iVar4) {

          FUN_140210920(iVar4,&local_48);

        }

      }

      FUN_1401841e0(uStack_40);

      FUN_1401841e0(pcVar8);

      DAT_1403fd3d0 = lVar7;

      return 1;

    }

  }

  return 0;

}





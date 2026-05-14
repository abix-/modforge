// Address: 0x140189820
// Ghidra name: FUN_140189820
// ============ 0x140189820 FUN_140189820 (size=623) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined1 FUN_140189820(longlong param_1,undefined8 param_2)



{

  short *psVar1;

  ushort uVar2;

  undefined1 auVar3 [16];

  undefined1 auVar4 [16];

  uint uVar5;

  undefined1 uVar6;

  char cVar7;

  int iVar8;

  ulonglong uVar9;

  undefined2 *puVar10;

  ulonglong uVar11;

  uint uVar12;

  ulonglong uVar13;

  ulonglong uVar14;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  

  uVar14 = (ulonglong)*(ushort *)(param_1 + 0x24);

  uVar2 = *(ushort *)(param_1 + 0x32);

  uVar11 = uVar2 * uVar14;

  local_28 = _DAT_140339980;

  uStack_20 = _UNK_140339988;

  local_18 = 0xf0;

  local_14 = 0xff3001cc;

  uVar9 = ((ulonglong)*(ushort *)(param_1 + 0x30) + uVar14 * -7) * 8;

  uVar13 = 0;

  local_10 = 0xff180188;

  auVar3._8_8_ = 0;

  auVar3._0_8_ = uVar11;

  auVar4._8_8_ = 0;

  auVar4._0_8_ = uVar9;

  if (*(ushort *)(param_1 + 0x24) < 3) {

    if (uVar2 == 4) {

      if ((ulonglong)*(ushort *)(param_1 + 0x30) < uVar14 * 7) {

        uVar6 = FUN_14012e850("Invalid MS ADPCM block size (nBlockAlign)");

      }

      else if (*(short *)(param_1 + 0x20) == -2) {

        uVar6 = FUN_14012e850("MS ADPCM with the extensible header is not supported");

      }

      else if (*(ulonglong *)(param_1 + 0x18) < 0x16) {

        uVar6 = FUN_14012e850("Could not read MS ADPCM format header");

      }

      else {

        *(uint *)(param_1 + 0x38) = (uint)*(ushort *)(*(longlong *)(param_1 + 0x10) + 0x12);

        uVar14 = (ulonglong)*(ushort *)(*(longlong *)(param_1 + 0x10) + 0x14);

        if (0x100 < uVar14) {

          uVar14 = 0x100;

        }

        if (*(ulonglong *)(param_1 + 0x18) < uVar14 * 4 + 0x16) {

          uVar6 = FUN_14012e850("Could not read custom coefficients in MS ADPCM format header");

        }

        else if ((ulonglong)*(ushort *)(param_1 + 0x34) < uVar14 * 4 + 4) {

          uVar6 = FUN_14012e850("Invalid MS ADPCM format header (too small)");

        }

        else if (uVar14 < 7) {

          uVar6 = FUN_14012e850("Missing required coefficients in MS ADPCM format header");

        }

        else {

          puVar10 = (undefined2 *)FUN_1401841f0(uVar14 * 4 + 0x18,uVar9 % uVar11);

          *(undefined2 **)(param_1 + 0x60) = puVar10;

          uVar6 = 0;

          if (puVar10 != (undefined2 *)0x0) {

            *puVar10 = (short)uVar14;

            *(undefined2 **)(puVar10 + 4) = puVar10 + 8;

            if (uVar14 != 0) {

              do {

                psVar1 = (short *)((longlong)&local_28 + uVar13 * 2);

                uVar12 = (uint)CONCAT11(*(undefined1 *)

                                         (*(longlong *)(param_1 + 0x10) + 0x17 + uVar13 * 2),

                                        *(undefined1 *)

                                         (*(longlong *)(param_1 + 0x10) +

                                          (0x16 - (longlong)&local_28) + (longlong)psVar1));

                uVar5 = uVar12 - 0x10000;

                if (uVar12 < 0x8000) {

                  uVar5 = uVar12;

                }

                if ((uVar13 < 0xe) && (uVar5 != (int)*psVar1)) {

                  uVar6 = FUN_14012e850("Wrong preset coefficients in MS ADPCM format header");

                  return uVar6;

                }

                *(short *)(*(longlong *)(puVar10 + 4) + uVar13 * 2) = (short)uVar5;

                uVar13 = uVar13 + 1;

              } while (uVar13 < uVar14 * 2);

            }

            iVar8 = *(int *)(param_1 + 0x38);

            if (iVar8 == 0) {

              iVar8 = SUB164(auVar4 / auVar3,0) + 2;

              *(int *)(param_1 + 0x38) = iVar8;

            }

            if ((iVar8 == 1) || (SUB168(auVar4 / auVar3,0) < (ulonglong)(iVar8 - 2))) {

              uVar6 = FUN_14012e850(

                                   "Invalid number of samples per MS ADPCM block (wSamplesPerBlock)"

                                   );

            }

            else {

              cVar7 = FUN_140189250(param_1,param_2);

              uVar6 = cVar7 != '\0';

            }

          }

        }

      }

    }

    else {

      uVar6 = FUN_14012e850("Invalid MS ADPCM bits per sample of %u",(ulonglong)uVar2);

    }

  }

  else {

    uVar6 = FUN_14012e850("Invalid number of channels");

  }

  return uVar6;

}





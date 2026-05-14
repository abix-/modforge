// Address: 0x140225180
// Ghidra name: FUN_140225180
// ============ 0x140225180 FUN_140225180 (size=689) ============


longlong FUN_140225180(void)



{

  ushort uVar1;

  int iVar2;

  uint uVar3;

  UINT UVar4;

  int iVar5;

  int iVar6;

  longlong lVar7;

  undefined4 *puVar8;

  uint uCode;

  undefined4 uVar9;

  ushort *puVar10;

  int *piVar11;

  uint local_res8;

  ushort local_158 [24];

  BYTE local_128 [16];

  byte local_118;

  byte local_117;

  byte local_116;

  byte local_114;

  

  FUN_1402f94c0(local_128,0,0x100);

  local_158[0] = 0;

  local_158[1] = 3;

  local_158[2] = 0x2000;

  local_158[3] = 0x2003;

  local_158[4] = 0x4000;

  local_158[5] = 0x4003;

  local_158[6] = 0x6000;

  local_158[7] = 0x6003;

  FUN_140225a20();

  lVar7 = FUN_140181910(0);

  if (lVar7 != 0) {

    puVar10 = local_158;

    local_res8 = 0;

    do {

      uCode = 0;

      piVar11 = &DAT_1403566e0;

      do {

        iVar2 = *piVar11;

        if (((iVar2 == 0) || (iVar2 == 0x4c)) ||

           (uVar3 = FUN_1401829a0(0,iVar2,0), (uVar3 >> 0x1e & 1) != 0)) {

          if ((*puVar10 == 0) && ((iVar2 == 0x39 || (iVar2 == 0x2a)))) {

            UVar4 = MapVirtualKeyW(uCode,1);

            if ((char)UVar4 == '\x14') {

              FUN_140182c80(lVar7,iVar2,0,0x40000039);

            }

            else if ((char)UVar4 == '\b') {

              FUN_140182c80(lVar7,iVar2,0,8);

            }

          }

        }

        else {

          uVar3 = -(uint)((uCode & 0x80) != 0) & 0xe000 | uCode & 0x7f;

          UVar4 = MapVirtualKeyW(uVar3,1);

          if ((char)UVar4 != '\0') {

            uVar1 = *puVar10;

            local_118 = -((uVar1 & 3) != 0) & 0x80;

            local_114 = (byte)(uVar1 >> 0xd) & 1;

            local_117 = (byte)(uVar1 >> 7) & 0x80;

            local_116 = local_117;

            iVar5 = ToUnicode(UVar4 & 0xff,uVar3,local_128,(LPWSTR)(local_158 + 8),0x10,0);

            iVar6 = FUN_140190050(iVar5);

            local_158[(longlong)iVar6 + 8] = 0;

            iVar6 = FUN_140190050(iVar5);

            puVar8 = (undefined4 *)

                     FUN_140197820("UTF-32LE","UTF-16LE",local_158 + 8,(longlong)iVar6 * 2 + 2);

            if (puVar8 == (undefined4 *)0x0) {

              if ((uVar1 >> 0xe & 1) == 0) {

                FUN_140182c80(lVar7,iVar2,uVar1,0);

              }

            }

            else {

              if (puVar8[1] == 0) {

                uVar9 = *puVar8;

              }

              else {

                uVar9 = 0xfffd;

              }

              FUN_140182c80(lVar7,iVar2,uVar1,uVar9);

              FUN_1401841e0();

            }

            if (iVar5 < 0) {

              FUN_140225a20();

            }

          }

        }

        uCode = uCode + 1;

        piVar11 = piVar11 + 1;

      } while (uCode < 0x100);

      puVar10 = puVar10 + 1;

      local_res8 = local_res8 + 1;

    } while (local_res8 < 8);

    return lVar7;

  }

  return 0;

}





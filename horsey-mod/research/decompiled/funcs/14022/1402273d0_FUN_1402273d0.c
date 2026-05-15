// Address: 0x1402273d0
// Ghidra name: FUN_1402273d0
// ============ 0x1402273d0 FUN_1402273d0 (size=340) ============


longlong FUN_1402273d0(longlong param_1,longlong *param_2)



{

  byte *pbVar1;

  int iVar2;

  uint uVar3;

  longlong lVar4;

  longlong lVar5;

  int iVar6;

  uint uVar7;

  longlong lVar8;

  char local_res8 [8];

  longlong *local_res10;

  undefined1 local_res18 [8];

  undefined1 local_res20 [8];

  undefined1 local_58 [24];

  

  iVar2 = *(int *)(param_1 + 8) + 7;

  uVar3 = (int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3;

  uVar7 = uVar3 & 0x80000003;

  if ((int)uVar7 < 0) {

    uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;

  }

  iVar2 = 4 - uVar7;

  if (uVar7 == 0) {

    iVar2 = 0;

  }

  iVar2 = iVar2 + uVar3;

  lVar8 = (longlong)(iVar2 * *(int *)(param_1 + 0xc));

  local_res10 = param_2;

  lVar4 = FUN_1401841f0(lVar8);

  if (lVar4 != 0) {

    FUN_1402f94c0(lVar4,0xff,lVar8);

    iVar6 = *(int *)(param_1 + 0xc) + -1;

    if (-1 < iVar6) {

      lVar5 = lVar4;

      do {

        uVar3 = 0;

        if (0 < *(int *)(param_1 + 8)) {

          do {

            FUN_140147b80(param_1,uVar3,iVar6,local_58,local_res20,local_res18,local_res8);

            if (local_res8[0] != '\0') {

              pbVar1 = (byte *)(((longlong)(int)uVar3 >> 3) + lVar5);

              *pbVar1 = *pbVar1 & ~(&DAT_140356d20)[uVar3 & 7];

            }

            uVar3 = uVar3 + 1;

          } while ((int)uVar3 < *(int *)(param_1 + 8));

        }

        lVar5 = lVar5 + iVar2;

        iVar6 = iVar6 + -1;

        param_2 = local_res10;

      } while (-1 < iVar6);

    }

    *param_2 = lVar8;

    return lVar4;

  }

  return 0;

}





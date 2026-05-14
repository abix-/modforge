// Address: 0x1402f3ee0
// Ghidra name: FUN_1402f3ee0
// ============ 0x1402f3ee0 FUN_1402f3ee0 (size=501) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



void FUN_1402f3ee0(longlong param_1)



{

  byte bVar1;

  byte bVar2;

  BOOL BVar3;

  uint uVar4;

  byte *pbVar5;

  undefined1 *puVar6;

  ulonglong uVar7;

  BYTE *pBVar8;

  byte *pbVar9;

  longlong lVar10;

  undefined1 auStack_788 [32];

  byte *local_768;

  undefined1 *local_760;

  undefined4 local_758;

  undefined4 local_750;

  undefined4 local_748;

  _cpinfo local_738;

  undefined1 local_718 [231];

  byte abStack_631 [25];

  undefined1 local_618 [231];

  byte abStack_531 [25];

  undefined1 local_518 [256];

  byte local_418 [1024];

  ulonglong local_18;

  

  local_18 = DAT_1403e8b00 ^ (ulonglong)auStack_788;

  local_738.LeadByte[10] = '\0';

  local_738.LeadByte[0xb] = '\0';

  local_738._18_2_ = 0;

  local_738.MaxCharSize = 0;

  local_738.DefaultChar[0] = '\0';

  local_738.DefaultChar[1] = '\0';

  local_738.LeadByte[0] = '\0';

  local_738.LeadByte[1] = '\0';

  local_738.LeadByte[2] = '\0';

  local_738.LeadByte[3] = '\0';

  local_738.LeadByte[4] = '\0';

  local_738.LeadByte[5] = '\0';

  local_738.LeadByte[6] = '\0';

  local_738.LeadByte[7] = '\0';

  local_738.LeadByte[8] = '\0';

  local_738.LeadByte[9] = '\0';

  if ((*(UINT *)(param_1 + 4) == 0xfde9) ||

     (BVar3 = GetCPInfo(*(UINT *)(param_1 + 4),&local_738), BVar3 == 0)) {

    uVar4 = 0;

    pbVar5 = (byte *)(param_1 + 0x19);

    do {

      if (uVar4 - 0x41 < 0x1a) {

        *pbVar5 = *pbVar5 | 0x10;

        bVar2 = (char)uVar4 + 0x20;

      }

      else if (uVar4 - 0x61 < 0x1a) {

        *pbVar5 = *pbVar5 | 0x20;

        bVar2 = (char)uVar4 - 0x20;

      }

      else {

        bVar2 = 0;

      }

      pbVar5[0x100] = bVar2;

      uVar4 = uVar4 + 1;

      pbVar5 = pbVar5 + 1;

    } while (uVar4 < 0x100);

  }

  else {

    uVar4 = 0;

    puVar6 = local_718;

    lVar10 = 0x100;

    do {

      *puVar6 = (char)uVar4;

      uVar4 = uVar4 + 1;

      puVar6 = puVar6 + 1;

    } while (uVar4 < 0x100);

    pBVar8 = local_738.LeadByte;

    local_718[0] = 0x20;

    bVar2 = local_738.LeadByte[0];

    while (bVar2 != 0) {

      bVar1 = pBVar8[1];

      uVar7 = (ulonglong)bVar2;

      while ((uVar4 = (uint)uVar7, uVar4 <= bVar1 && (uVar4 < 0x100))) {

        local_718[uVar7] = 0x20;

        uVar7 = (ulonglong)(uVar4 + 1);

      }

      pBVar8 = pBVar8 + 2;

      bVar2 = *pBVar8;

    }

    local_758 = 0;

    local_760 = (undefined1 *)CONCAT44(local_760._4_4_,*(undefined4 *)(param_1 + 4));

    local_768 = local_418;

    FUN_1402f2fc0(0,1,local_718,0x100);

    local_748 = 0;

    local_750 = *(undefined4 *)(param_1 + 4);

    local_760 = local_618;

    local_758 = 0x100;

    local_768._0_4_ = 0x100;

    __acrt_LCMapStringA(0,*(undefined8 *)(param_1 + 0x220),0x100,local_718);

    local_748 = 0;

    local_750 = *(undefined4 *)(param_1 + 4);

    local_760 = local_518;

    local_758 = 0x100;

    local_768 = (byte *)CONCAT44(local_768._4_4_,0x100);

    __acrt_LCMapStringA(0,*(undefined8 *)(param_1 + 0x220),0x200,local_718);

    pbVar9 = local_418;

    pbVar5 = (byte *)(param_1 + 0x19);

    do {

      if ((*pbVar9 & 1) == 0) {

        if ((*pbVar9 & 2) == 0) {

          bVar2 = 0;

        }

        else {

          *pbVar5 = *pbVar5 | 0x20;

          bVar2 = pbVar5[(longlong)(abStack_531 + -param_1)];

        }

      }

      else {

        *pbVar5 = *pbVar5 | 0x10;

        bVar2 = pbVar5[(longlong)(abStack_631 + -param_1)];

      }

      pbVar5[0x100] = bVar2;

      pbVar9 = pbVar9 + 2;

      pbVar5 = pbVar5 + 1;

      lVar10 = lVar10 + -1;

    } while (lVar10 != 0);

  }

  return;

}





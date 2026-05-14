// Address: 0x1400d1c40
// Ghidra name: FUN_1400d1c40
// ============ 0x1400d1c40 FUN_1400d1c40 (size=386) ============


void FUN_1400d1c40(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  ulonglong *puVar1;

  size_t sVar2;

  ulonglong uVar3;

  longlong lVar4;

  ulonglong uVar5;

  undefined8 local_res20;

  undefined4 uVar6;

  longlong local_48 [4];

  

  local_res20 = param_4;

  puVar1 = (ulonglong *)FUN_140023ec0();

  uVar6 = 0;

  FUN_1402d7d00(*puVar1 | 2,&DAT_1403f35f0,0x3ff,param_3,0,&local_res20);

  local_48[0] = 0;

  local_48[1] = 0;

  local_48[2] = 0;

  local_48[3] = 0;

  sVar2 = strlen(&DAT_1403f35f0);

  if (0x7fffffffffffffff < sVar2) {

                    /* WARNING: Subroutine does not return */

    FUN_140024130();

  }

  if (sVar2 < 0x10) {

    local_48[3] = 0xf;

    local_48[2] = sVar2;

    FUN_1402f8e20(local_48,&DAT_1403f35f0,sVar2);

    *(undefined1 *)((longlong)local_48 + sVar2) = 0;

  }

  else {

    uVar3 = sVar2 | 0xf;

    uVar5 = 0x7fffffffffffffff;

    if ((uVar3 < 0x8000000000000000) && (uVar5 = uVar3, uVar3 < 0x16)) {

      uVar5 = 0x16;

    }

    lVar4 = FUN_1400285e0(uVar5 + 1);

    local_48[0] = lVar4;

    local_48[2] = sVar2;

    local_48[3] = uVar5;

    FUN_1402f8e20(lVar4,&DAT_1403f35f0,sVar2);

    *(undefined1 *)(lVar4 + sVar2) = 0;

  }

  FUN_1400d0c80(param_1,param_2,local_48,0,CONCAT44(uVar6,DAT_140303758));

  if (0xf < (ulonglong)local_48[3]) {

    if (0xfff < local_48[3] + 1U) {

      if (0x1f < (local_48[0] - *(longlong *)(local_48[0] + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  return;

}





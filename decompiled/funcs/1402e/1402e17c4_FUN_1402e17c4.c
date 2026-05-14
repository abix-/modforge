// Address: 0x1402e17c4
// Ghidra name: FUN_1402e17c4
// ============ 0x1402e17c4 FUN_1402e17c4 (size=225) ============


void FUN_1402e17c4(undefined8 param_1,undefined4 *param_2,undefined8 *param_3,undefined4 *param_4)



{

  longlong *plVar1;

  uint uVar2;

  longlong *plVar3;

  undefined1 local_res10 [16];

  undefined4 *local_res20;

  longlong local_58;

  longlong local_50;

  longlong local_48;

  longlong *local_40;

  longlong *local_38;

  undefined8 local_30;

  undefined8 local_28;

  undefined8 local_20;

  

  local_res20 = param_4;

  __acrt_lock(*param_2);

  plVar1 = DAT_1403fed30 + DAT_1403fed28;

  for (plVar3 = DAT_1403fed30; local_40 = plVar3, plVar3 != plVar1; plVar3 = plVar3 + 1) {

    local_58 = *plVar3;

    if ((local_58 != 0) && (uVar2 = *(uint *)(local_58 + 0x14), (uVar2 >> 0xd & 1) != 0)) {

      if (((((byte)uVar2 & 3) == 2) && ((uVar2 & 0xc0) != 0)) || ((uVar2 >> 0xb & 1) != 0)) {

        local_20 = param_3[2];

        local_28 = param_3[1];

        local_30 = *param_3;

        local_38 = &local_58;

        local_50 = local_58;

        local_48 = local_58;

        FUN_1402e1728(local_res10,&local_48,&local_38,&local_50);

      }

      else {

        *(int *)*param_3 = *(int *)*param_3 + 1;

      }

    }

  }

  __acrt_unlock(*param_4);

  return;

}





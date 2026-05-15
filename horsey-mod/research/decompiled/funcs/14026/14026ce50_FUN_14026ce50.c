// Address: 0x14026ce50
// Ghidra name: FUN_14026ce50
// ============ 0x14026ce50 FUN_14026ce50 (size=142) ============


void FUN_14026ce50(undefined8 param_1,byte param_2)



{

  float fVar1;

  undefined1 auVar2 [16];

  undefined1 auVar3 [16];

  undefined1 local_res10;

  char local_res11;

  char local_res12;

  undefined1 local_res13;

  undefined8 extraout_XMM0_Qb;

  

  local_res11 = '\0';

  if (param_2 != 0) {

    if (param_2 < 0x41) {

      local_res11 = (char)((ulonglong)(param_2 + 5) / 10);

    }

    else {

      auVar2._0_8_ = thunk_FUN_1402d8d60((float)param_2 / DAT_14039ca5c,DAT_14037efa0);

      auVar2._8_8_ = extraout_XMM0_Qb;

      auVar3._4_12_ = auVar2._4_12_;

      auVar3._0_4_ = (float)auVar2._0_8_ * DAT_1403033a8;

      fVar1 = (float)thunk_FUN_1402e33f0(auVar3._0_8_);

      local_res11 = (char)(int)fVar1;

    }

  }

  local_res11 = local_res11 << 4;

  local_res10 = 1;

  local_res13 = 0;

  local_res12 = local_res11;

  FUN_14026d5b0(param_1,0x38,&local_res10,4,0);

  return;

}





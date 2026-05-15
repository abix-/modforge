// Address: 0x1402e99e0
// Ghidra name: FUN_1402e99e0
// ============ 0x1402e99e0 FUN_1402e99e0 (size=154) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 * FUN_1402e99e0(char *param_1,undefined8 param_2,int param_3,undefined8 *param_4)



{

  undefined8 uVar1;

  errno_t eVar2;

  undefined8 *puVar3;

  undefined8 *puVar4;

  int local_res18 [2];

  int local_28;

  uint uStack_24;

  char local_18 [16];

  

  puVar3 = (undefined8 *)__acrt_stdio_parse_mode<char>(local_18);

  uVar1 = *puVar3;

  puVar4 = (undefined8 *)0x0;

  if (*(char *)(puVar3 + 1) != '\0') {

    local_28 = (int)uVar1;

    local_res18[0] = 0;

    eVar2 = FID_conflict__sopen_s(local_res18,param_1,local_28,param_3,0x180);

    if (eVar2 == 0) {

      _DAT_1403fed38 = _DAT_1403fed38 + 1;

      uStack_24 = (uint)((ulonglong)uVar1 >> 0x20);

      LOCK();

      *(uint *)((longlong)param_4 + 0x14) = *(uint *)((longlong)param_4 + 0x14) | uStack_24;

      UNLOCK();

      *(undefined4 *)(param_4 + 2) = 0;

      param_4[5] = 0;

      param_4[1] = 0;

      *param_4 = 0;

      *(int *)(param_4 + 3) = local_res18[0];

      puVar4 = param_4;

    }

  }

  return puVar4;

}





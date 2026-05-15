// Address: 0x14009e700
// Ghidra name: FUN_14009e700
// ============ 0x14009e700 FUN_14009e700 (size=165) ============


void FUN_14009e700(longlong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                  undefined4 param_5,undefined4 param_6,undefined8 param_7)



{

  ulonglong *puVar1;

  undefined1 *puVar2;

  

  puVar2 = &stack0x00000040;

  puVar1 = (ulonglong *)FUN_140023ec0();

  FUN_1402d7d00(*puVar1 | 2,&DAT_1403ee0a0,0x3ff,param_7,0,puVar2);

  *(undefined4 *)(param_1 + 0x24) = param_5;

  *(undefined4 *)(param_1 + 0x38) = param_6;

  FUN_14009e2f0(param_1,param_2,param_3,param_4,&DAT_1403ee0a0,

                (ulonglong)puVar2 & 0xffffffff00000000);

  return;

}





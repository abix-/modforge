// Address: 0x14009e7b0
// Ghidra name: FUN_14009e7b0
// ============ 0x14009e7b0 FUN_14009e7b0 (size=141) ============


void FUN_14009e7b0(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                  undefined8 param_5)



{

  ulonglong *puVar1;

  undefined1 *puVar2;

  

  puVar2 = &stack0x00000030;

  puVar1 = (ulonglong *)FUN_140023ec0();

  FUN_1402d7d00(*puVar1 | 2,&DAT_1403ee0a0,0x3ff,param_5,0,puVar2);

  FUN_14009e2f0(param_1,param_2,param_3,param_4,&DAT_1403ee0a0,

                (ulonglong)puVar2 & 0xffffffff00000000);

  return;

}





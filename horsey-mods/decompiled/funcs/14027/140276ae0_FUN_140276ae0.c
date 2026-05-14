// Address: 0x140276ae0
// Ghidra name: FUN_140276ae0
// ============ 0x140276ae0 FUN_140276ae0 (size=62) ============


void FUN_140276ae0(undefined8 *param_1)



{

  ulonglong uVar1;

  

  uVar1 = FUN_140149350();

  if (param_1[3] + 60000 <= uVar1) {

    FUN_1402771f0(*param_1,CONCAT71((int7)(param_1[3] + 60000 >> 8),1));

    param_1[3] = uVar1;

  }

  return;

}





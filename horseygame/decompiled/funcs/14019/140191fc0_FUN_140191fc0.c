// Address: 0x140191fc0
// Ghidra name: FUN_140191fc0
// ============ 0x140191fc0 FUN_140191fc0 (size=139) ============


undefined4 FUN_140191fc0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)



{

  char cVar1;

  undefined4 uVar2;

  longlong local_res8;

  

  local_res8 = 0;

  cVar1 = (*DAT_1403fcc90)(*param_1,&local_res8);

  if ((cVar1 != '\0') && (local_res8 != 0)) {

    uVar2 = FUN_140193970(local_res8,param_2,param_3);

    (*DAT_1403fcc98)(local_res8);

    return uVar2;

  }

  FUN_140196b60(param_1,L"HidD_GetPreparsedData");

  return 0xffffffff;

}





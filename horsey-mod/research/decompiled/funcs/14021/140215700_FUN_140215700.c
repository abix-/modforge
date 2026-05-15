// Address: 0x140215700
// Ghidra name: FUN_140215700
// ============ 0x140215700 FUN_140215700 (size=208) ============


bool FUN_140215700(longlong param_1)



{

  char cVar1;

  undefined1 uVar2;

  int iVar3;

  longlong *local_res8;

  

  local_res8 = (longlong *)0x0;

  cVar1 = FUN_140289bb0(param_1,&local_res8,*(undefined1 *)(param_1 + 0x94));

  if (cVar1 == '\0') {

    *(undefined8 *)(*(longlong *)(param_1 + 200) + 0x10) = 0;

    return false;

  }

  cVar1 = FUN_140289cb0(local_res8);

  *(bool *)(*(longlong *)(param_1 + 200) + 0x46) = cVar1 == '\0';

  iVar3 = (**(code **)(*local_res8 + 0x18))

                    (local_res8,&DAT_1403539e0,0x17,0,*(longlong *)(param_1 + 200) + 0x10);

  (**(code **)(*local_res8 + 0x10))();

  if (iVar3 < 0) {

    uVar2 = FUN_1401a9ef0("WASAPI can\'t activate audio endpoint",iVar3);

    return (bool)uVar2;

  }

  cVar1 = FUN_140215200(param_1);

  return cVar1 != '\0';

}





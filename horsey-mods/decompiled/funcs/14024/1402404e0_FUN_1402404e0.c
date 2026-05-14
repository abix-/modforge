// Address: 0x1402404e0
// Ghidra name: FUN_1402404e0
// ============ 0x1402404e0 FUN_1402404e0 (size=291) ============


undefined8 FUN_1402404e0(longlong *param_1,undefined8 param_2,undefined8 param_3)



{

  int iVar1;

  undefined8 uVar2;

  char *local_68;

  undefined4 local_60;

  undefined8 local_5c;

  undefined8 local_54;

  undefined4 local_4c;

  char *local_48;

  undefined4 local_40;

  undefined8 local_3c;

  undefined8 local_34;

  undefined4 local_2c;

  char *local_28;

  undefined4 local_20;

  undefined8 local_1c;

  undefined8 local_14;

  undefined4 local_c;

  

  local_68 = "POSITION";

  local_60 = 0;

  local_54 = 0;

  local_5c = 0x10;

  local_4c = 0;

  local_48 = "TEXCOORD";

  local_40 = 0;

  local_3c = 0x10;

  local_34 = 8;

  local_2c = 0;

  local_28 = "COLOR";

  local_20 = 0;

  local_c = 0;

  local_1c = 2;

  local_14 = 0x10;

  iVar1 = (**(code **)(*param_1 + 0x60))(param_1,&DAT_14035bb90,0x58c,0,param_2);

  if (iVar1 < 0) {

    uVar2 = FUN_1401a9ef0("ID3D11Device1::CreateVertexShader",iVar1);

    return uVar2;

  }

  iVar1 = (**(code **)(*param_1 + 0x58))(param_1,&local_68,3,&DAT_14035bb90,0x58c,param_3);

  if (iVar1 < 0) {

    uVar2 = FUN_1401a9ef0("ID3D11Device1::CreateInputLayout",iVar1);

    return uVar2;

  }

  return 1;

}





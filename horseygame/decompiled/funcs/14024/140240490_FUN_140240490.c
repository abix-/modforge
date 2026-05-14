// Address: 0x140240490
// Ghidra name: FUN_140240490
// ============ 0x140240490 FUN_140240490 (size=73) ============


undefined8 FUN_140240490(longlong *param_1,int param_2,undefined8 param_3)



{

  int iVar1;

  undefined8 uVar2;

  

  iVar1 = (**(code **)(*param_1 + 0x78))

                    (param_1,*(undefined8 *)(&DAT_1403e5560 + (longlong)param_2 * 0x10),

                     *(undefined8 *)(&DAT_1403e5568 + (longlong)param_2 * 0x10),0,param_3);

  if (iVar1 < 0) {

    uVar2 = FUN_1401a9ef0("ID3D11Device1::CreatePixelShader",iVar1);

    return uVar2;

  }

  return 1;

}





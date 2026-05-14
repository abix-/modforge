// Address: 0x1401e6cf0
// Ghidra name: FUN_1401e6cf0
// ============ 0x1401e6cf0 FUN_1401e6cf0 (size=668) ============


longlong FUN_1401e6cf0(longlong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                      undefined4 param_5)



{

  longlong lVar1;

  int iVar2;

  longlong lVar3;

  longlong *local_res8;

  char *local_318;

  undefined4 local_310;

  undefined8 local_30c;

  undefined8 local_304;

  undefined4 local_2fc;

  char *local_2f8;

  undefined4 local_2f0;

  undefined8 local_2ec;

  undefined8 local_2e4;

  undefined4 local_2dc;

  char *local_2d8;

  undefined4 local_2d0;

  undefined8 local_2cc;

  undefined8 local_2c4;

  undefined4 local_2bc;

  undefined8 local_2b8;

  undefined1 local_2b0 [16];

  undefined1 local_2a0 [96];

  undefined1 local_240 [328];

  undefined4 local_f8;

  undefined4 local_f4;

  undefined4 local_f0;

  undefined4 local_ec;

  undefined8 local_e8;

  undefined4 local_e0;

  undefined4 local_dc;

  undefined8 local_d8;

  char **local_90;

  undefined4 local_88;

  undefined4 local_7c;

  undefined4 local_78;

  undefined4 local_74;

  undefined8 local_50;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  local_318 = "POSITION";

  local_310 = 0;

  local_2f8 = "TEXCOORD";

  local_30c = 0x10;

  local_2d8 = "COLOR";

  local_304 = 0;

  local_2fc = 0;

  local_2f0 = 0;

  local_2ec = 0x10;

  local_2e4 = 8;

  local_2dc = 0;

  local_2d0 = 0;

  local_2cc = 2;

  local_2c4 = 0x10;

  local_2bc = 0;

  local_res8 = (longlong *)0x0;

  FUN_1402f94c0(local_2b0,0,0x288);

  iVar2 = FUN_140240650(param_2);

  local_2b8 = *(undefined8 *)(lVar1 + 0xe0 + (longlong)iVar2 * 8);

  FUN_140240670(param_2,local_2b0);

  FUN_140240610(param_2,local_2a0);

  FUN_1401e6100(param_1,param_3,local_240);

  local_90 = &local_318;

  local_f8 = 0xffffffff;

  local_d8 = 0;

  local_f0 = 1;

  local_e8 = 0;

  local_dc = 1;

  local_f4 = 3;

  local_ec = 0;

  local_e0 = 0;

  local_88 = 3;

  local_78 = 1;

  local_74 = param_5;

  local_50 = 1;

  local_7c = param_4;

  iVar2 = (**(code **)(**(longlong **)(lVar1 + 0x30) + 0x50))

                    (*(longlong **)(lVar1 + 0x30),&local_2b8,&DAT_14034bc80,&local_res8);

  if (iVar2 < 0) {

    FUN_1401a9ef0("ID3D12Device::CreateGraphicsPipelineState",iVar2);

    lVar3 = 0;

  }

  else {

    lVar3 = FUN_140184230(*(undefined8 *)(lVar1 + 0x100),

                          ((longlong)*(int *)(lVar1 + 0xf8) + 1) * 0x88);

    if (lVar3 == 0) {

      if (local_res8 != (longlong *)0x0) {

        (**(code **)(*local_res8 + 0x10))();

      }

      lVar3 = 0;

    }

    else {

      *(undefined4 *)((longlong)*(int *)(lVar1 + 0xf8) * 0x88 + lVar3) = param_2;

      *(undefined4 *)((longlong)*(int *)(lVar1 + 0xf8) * 0x88 + 0x74 + lVar3) = param_3;

      *(undefined4 *)((longlong)*(int *)(lVar1 + 0xf8) * 0x88 + 0x78 + lVar3) = param_4;

      *(undefined4 *)((longlong)*(int *)(lVar1 + 0xf8) * 0x88 + 0x7c + lVar3) = param_5;

      *(longlong **)((longlong)*(int *)(lVar1 + 0xf8) * 0x88 + 0x80 + lVar3) = local_res8;

      iVar2 = *(int *)(lVar1 + 0xf8);

      *(longlong *)(lVar1 + 0x100) = lVar3;

      *(int *)(lVar1 + 0xf8) = iVar2 + 1;

      lVar3 = (longlong)iVar2 * 0x88 + lVar3;

    }

  }

  return lVar3;

}





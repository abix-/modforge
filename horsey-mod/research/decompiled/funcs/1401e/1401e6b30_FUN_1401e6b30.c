// Address: 0x1401e6b30
// Ghidra name: FUN_1401e6b30
// ============ 0x1401e6b30 FUN_1401e6b30 (size=436) ============


undefined8 FUN_1401e6b30(longlong param_1,longlong param_2)



{

  longlong lVar1;

  int iVar2;

  undefined8 *puVar3;

  undefined8 uVar4;

  longlong lVar5;

  undefined4 local_98;

  undefined8 local_94;

  undefined4 local_8c;

  undefined8 local_88;

  undefined4 local_80;

  uint local_7c;

  undefined4 local_78;

  undefined4 local_74;

  undefined8 local_70;

  undefined8 local_68;

  undefined4 local_60;

  undefined8 local_5c;

  undefined4 local_54;

  undefined4 local_50;

  undefined4 local_48;

  undefined4 local_44;

  undefined4 local_40;

  undefined8 local_3c;

  uint local_34;

  undefined8 local_30;

  undefined8 uStack_28;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  puVar3 = (undefined8 *)FUN_1401841a0(1,0x20);

  uVar4 = 0;

  if (puVar3 != (undefined8 *)0x0) {

    *(undefined8 **)(param_2 + 0x10) = puVar3;

    if (*(longlong *)(lVar1 + 0x30) == 0) {

      uVar4 = FUN_14012e850("Device lost and couldn\'t be recovered");

    }

    else {

      local_94 = 0;

      local_8c = 0;

      local_70 = 0;

      local_68 = 0;

      local_88 = 0x100;

      local_80 = 1;

      local_7c = 0x10001;

      local_78 = FUN_1401eb330(0x16762004,*(undefined4 *)(param_1 + 0x208));

      local_74 = 1;

      local_98 = 3;

      local_5c = 0;

      local_60 = 1;

      local_54 = 1;

      local_50 = 1;

      iVar2 = (**(code **)(**(longlong **)(lVar1 + 0x30) + 0xd8))

                        (*(longlong **)(lVar1 + 0x30),&local_60,0,&local_98,0x400,0,&DAT_14034bc60,

                         puVar3);

      if (iVar2 < 0) {

        uVar4 = FUN_1401a9ef0("ID3D12Device::CreateCommittedResource [texture]",iVar2);

      }

      else {

        *(undefined4 *)(puVar3 + 2) = 0x400;

        local_30 = 0;

        uStack_28 = 0;

        local_3c = 0;

        local_40 = 0x1688;

        local_48 = FUN_1401eb280(0x16762004,*(undefined4 *)(param_1 + 0x208));

        local_34 = local_7c >> 0x10;

        local_44 = 4;

        (**(code **)(**(longlong **)(lVar1 + 0x80) + 0x48))(*(longlong **)(lVar1 + 0x80),puVar3 + 1)

        ;

        lVar5 = FUN_1401e7e70(param_1);

        puVar3[3] = lVar5;

        puVar3[1] = puVar3[1] + (ulonglong)*(uint *)(lVar1 + 0x88) * lVar5;

        (**(code **)(**(longlong **)(lVar1 + 0x30) + 0x90))

                  (*(longlong **)(lVar1 + 0x30),*puVar3,&local_48,puVar3[1]);

        uVar4 = 1;

      }

    }

  }

  return uVar4;

}





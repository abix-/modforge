// Address: 0x1401e1650
// Ghidra name: FUN_1401e1650
// ============ 0x1401e1650 FUN_1401e1650 (size=325) ============


undefined8 FUN_1401e1650(longlong param_1,longlong param_2)



{

  longlong lVar1;

  int iVar2;

  undefined8 *puVar3;

  undefined8 uVar4;

  undefined4 local_58;

  undefined8 local_54;

  undefined4 local_4c;

  undefined8 local_48;

  undefined4 local_40;

  undefined4 local_3c;

  undefined4 local_38;

  undefined4 local_34;

  undefined4 local_30;

  undefined8 local_2c;

  undefined4 local_24;

  undefined4 local_20;

  undefined8 local_1c;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  puVar3 = (undefined8 *)FUN_1401841a0(1,0x10);

  uVar4 = 0;

  if (puVar3 != (undefined8 *)0x0) {

    *(undefined8 **)(param_2 + 0x10) = puVar3;

    if (*(longlong *)(lVar1 + 0x20) == 0) {

      uVar4 = FUN_14012e850("Device lost and couldn\'t be recovered");

    }

    else {

      local_40 = 0x100;

      local_3c = 1;

      local_38 = 1;

      local_34 = 1;

      local_30 = FUN_1401e5c00(0x16762004,*(undefined4 *)(param_1 + 0x208));

      local_2c = 1;

      local_1c = 0;

      local_24 = 0;

      local_20 = 8;

      iVar2 = (**(code **)(**(longlong **)(lVar1 + 0x20) + 0x28))

                        (*(longlong **)(lVar1 + 0x20),&local_40,0,puVar3);

      if (iVar2 < 0) {

        uVar4 = FUN_1401a9ef0("ID3D11Device1::CreateTexture2D",iVar2);

      }

      else {

        local_48 = 0;

        local_58 = FUN_1401e5b50(0x16762004,*(undefined4 *)(param_1 + 0x208));

        local_4c = local_38;

        local_54 = 4;

        iVar2 = (**(code **)(**(longlong **)(lVar1 + 0x20) + 0x38))

                          (*(longlong **)(lVar1 + 0x20),*puVar3,&local_58,puVar3 + 1);

        if (iVar2 < 0) {

          uVar4 = FUN_1401a9ef0("ID3D11Device1::CreateShaderResourceView",iVar2);

        }

        else {

          uVar4 = 1;

        }

      }

    }

  }

  return uVar4;

}





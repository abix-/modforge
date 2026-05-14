// Address: 0x14020fc00
// Ghidra name: FUN_14020fc00
// ============ 0x14020fc00 FUN_14020fc00 (size=174) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14020fc00(longlong param_1)



{

  undefined8 *puVar1;

  longlong lVar2;

  char cVar3;

  int iVar4;

  longlong *local_res8;

  

  puVar1 = (undefined8 *)**(longlong **)(param_1 + 0x148);

  lVar2 = puVar1[0xe];

  local_res8 = (longlong *)0x0;

  iVar4 = (**(code **)(*DAT_1403fd3b0 + 0x20))

                    (DAT_1403fd3b0,*(undefined4 *)(lVar2 + 0x68),*puVar1,&local_res8);

  if (-1 < iVar4) {

    (**(code **)(*local_res8 + 0x28))();

    if (*(int *)(puVar1 + 0xf) == 1) {

      FUN_1402102e0(param_1,local_res8);

    }

    else {

      cVar3 = FUN_140210780(lVar2);

      if (cVar3 == '\0') {

        FUN_14020fe40(param_1,local_res8);

      }

      else {

        FUN_140210060();

      }

    }

    (**(code **)(*local_res8 + 0x10))();

  }

  return;

}





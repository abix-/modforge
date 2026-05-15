// Address: 0x14015ec40
// Ghidra name: FUN_14015ec40
// ============ 0x14015ec40 FUN_14015ec40 (size=349) ============


longlong FUN_14015ec40(undefined8 param_1,undefined8 *param_2,longlong param_3,undefined8 param_4)



{

  char cVar1;

  int iVar2;

  longlong lVar3;

  longlong lVar4;

  undefined8 *puVar5;

  longlong lVar6;

  undefined8 *puVar7;

  longlong local_48;

  undefined8 local_40;

  undefined4 local_38;

  

  iVar2 = FUN_14015eda0();

  if (iVar2 == 0) {

    return 0;

  }

  local_48 = 0;

  lVar3 = FUN_14015cb20(iVar2,&local_48);

  lVar6 = local_48;

  if (lVar3 != 0) {

    FUN_140139010(lVar3 + 0x10,1);

    lVar6 = local_48;

    cVar1 = *(char *)(local_48 + 0x94);

    if (param_2 == (undefined8 *)0x0) {

      local_40 = *(undefined8 *)(local_48 + 0x60);

      local_38 = *(undefined4 *)(local_48 + 0x68);

      param_2 = &local_40;

    }

    if (cVar1 == '\0') {

      puVar7 = (undefined8 *)(local_48 + 0x60);

      puVar5 = param_2;

    }

    else {

      puVar5 = (undefined8 *)(local_48 + 0x60);

      puVar7 = param_2;

    }

    lVar4 = FUN_140167620(puVar5,puVar7);

    if (lVar4 != 0) {

      *(longlong *)(lVar3 + 0x18) = lVar4;

      *(undefined1 *)(lVar3 + 0x21) = 1;

      *(longlong *)(lVar4 + 0xc0) = lVar3;

      *(undefined1 *)(lVar4 + 0xb8) = 1;

      FUN_14015fec0(lVar6);

      if (param_3 != 0) {

        if (cVar1 == '\0') {

          FUN_1401685b0(lVar4,param_3,param_4);

        }

        else {

          FUN_140168680();

        }

      }

      FUN_14015d3e0(lVar6);

      return lVar4;

    }

  }

  FUN_14015d3e0(lVar6);

  FUN_1401676f0(0);

  FUN_14015ddd0(iVar2);

  return 0;

}





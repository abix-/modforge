// Address: 0x1401b5a30
// Ghidra name: FUN_1401b5a30
// ============ 0x1401b5a30 FUN_1401b5a30 (size=606) ============


longlong FUN_1401b5a30(longlong param_1,undefined8 param_2,uint param_3,int param_4,

                      undefined1 param_5,longlong param_6)



{

  char cVar1;

  uint uVar2;

  int iVar3;

  longlong lVar4;

  undefined8 uVar5;

  uint uVar6;

  undefined4 local_78 [2];

  undefined8 local_70;

  undefined4 local_68;

  undefined8 local_60;

  longlong local_58;

  undefined4 local_50 [2];

  undefined8 local_48;

  undefined4 local_40;

  undefined8 local_38;

  uint local_30;

  undefined4 local_2c;

  undefined4 local_28;

  longlong local_20;

  

  uVar6 = (param_3 & 1) << 7;

  uVar2 = uVar6 | 0x40;

  if ((param_3 & 2) == 0) {

    uVar2 = uVar6;

  }

  uVar6 = uVar2 | 0x20;

  if ((param_3 & 0x38) == 0) {

    uVar6 = uVar2;

  }

  lVar4 = FUN_1401841a0(1,0x40);

  *(undefined8 *)(lVar4 + 0x28) = param_2;

  *(uint *)(lVar4 + 0x24) = param_3;

  *(int *)(lVar4 + 0x20) = param_4;

  local_30 = uVar6 | 0x100;

  if ((param_3 & 4) == 0) {

    local_30 = uVar6;

  }

  *(undefined2 *)(lVar4 + 0x34) = 0;

  local_20 = param_1 + 0x7c0;

  local_50[0] = 0xc;

  uVar2 = 0x13;

  if (param_4 != 1) {

    uVar2 = 3;

  }

  local_48 = 0;

  local_30 = local_30 | uVar2;

  local_40 = 0;

  local_2c = 0;

  local_28 = 1;

  local_38 = param_2;

  iVar3 = (**(code **)(param_1 + 0xaf0))(*(undefined8 *)(param_1 + 0x570),local_50,0,lVar4 + 0x10);

  if (iVar3 == 0) {

    cVar1 = FUN_1401b47a0(param_1,*(undefined8 *)(lVar4 + 0x10),*(undefined8 *)(lVar4 + 0x28),

                          *(undefined4 *)(lVar4 + 0x20),param_5,(longlong *)(lVar4 + 0x18));

    if (cVar1 == '\x01') {

      *(longlong *)(*(longlong *)(lVar4 + 0x18) + 0x38) = lVar4;

      FUN_140139010(lVar4 + 0x30,0);

      if (((*(char *)(param_1 + 0x57c) != '\0') && (*(char *)(param_1 + 0x58e) != '\0')) &&

         (param_6 != 0)) {

        local_58 = param_6;

        local_60 = *(undefined8 *)(lVar4 + 0x10);

        local_78[0] = 0x3b9cbe00;

        local_70 = 0;

        local_68 = 9;

        (**(code **)(param_1 + 0x9d0))(*(undefined8 *)(param_1 + 0x570),local_78);

      }

    }

    else {

      (**(code **)(param_1 + 0xb70))

                (*(undefined8 *)(param_1 + 0x570),*(undefined8 *)(lVar4 + 0x10),0);

      FUN_1401841e0(lVar4);

      if (*(char *)(param_1 + 0x57c) != '\0') {

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(9,&DAT_14039bf30,"Failed to bind memory for buffer!");

      }

      FUN_14012e850(&DAT_14039bf30,"Failed to bind memory for buffer!");

      lVar4 = 0;

    }

  }

  else {

    FUN_1401841e0(lVar4);

    if (*(char *)(param_1 + 0x57c) != '\0') {

      uVar5 = FUN_1401c0ba0(iVar3);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"%s %s","vkCreateBuffer",uVar5);

    }

    uVar5 = FUN_1401c0ba0(iVar3);

    FUN_14012e850("%s %s","vkCreateBuffer",uVar5);

    lVar4 = 0;

  }

  return lVar4;

}





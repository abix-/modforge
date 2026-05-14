// Address: 0x14027e5d0
// Ghidra name: FUN_14027e5d0
// ============ 0x14027e5d0 FUN_14027e5d0 (size=153) ============


undefined8

FUN_14027e5d0(longlong param_1,undefined8 param_2,undefined8 param_3,short param_4,ushort param_5,

             undefined2 param_6)



{

  ushort uVar1;

  uint uVar2;

  int iVar3;

  uint *puVar4;

  

  if (param_4 == 0x46d) {

    puVar4 = &DAT_1403e66b8;

    uVar2 = 0;

    do {

      if (*puVar4 == (uint)param_5) break;

      uVar2 = uVar2 + 1;

      puVar4 = puVar4 + 1;

    } while (uVar2 < 6);

    if (uVar2 != 6) {

      uVar1 = FUN_14027f2b0(param_5,param_6);

      if (((uVar1 != param_5) && (uVar1 != 0)) && (param_1 != 0)) {

        iVar3 = FUN_14027fa20("SDL_HIDAPI_LG4FF_NO_MODE_SWITCH",0,1,0);

        if (iVar3 == 0) {

          FUN_14027f900(param_1,uVar1);

        }

      }

      return 1;

    }

  }

  return 0;

}





// Address: 0x14022e060
// Ghidra name: FUN_14022e060
// ============ 0x14022e060 FUN_14022e060 (size=364) ============


void FUN_14022e060(int param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)



{

  undefined1 uVar1;

  undefined4 uVar2;

  undefined8 uVar3;

  undefined8 uVar4;

  undefined8 uVar5;

  undefined8 uVar6;

  undefined8 uVar7;

  undefined8 uVar8;

  undefined1 uVar9;

  

  uVar3 = FUN_140174d30(param_4,"SDL.filedialog.window",0);

  uVar4 = FUN_140174d30(param_4,"SDL.filedialog.filters",0);

  uVar2 = FUN_140174c40(param_4,"SDL.filedialog.nfilters",0);

  uVar1 = FUN_1401749e0(param_4,"SDL.filedialog.many",0);

  uVar5 = FUN_140174e70(param_4,"SDL.filedialog.location",0);

  uVar6 = FUN_140174e70(param_4,"SDL.filedialog.title",0);

  uVar7 = FUN_140174e70(param_4,"SDL.filedialog.accept",0);

  uVar8 = FUN_140174e70(param_4,"SDL.filedialog.cancel",0);

  uVar9 = 0;

  if (param_1 != 0) {

    if (param_1 != 1) {

      if (param_1 != 2) {

        return;

      }

      FUN_14022e3c0(param_2,param_3,uVar3,uVar5,uVar1,uVar6,uVar7,uVar8);

      return;

    }

    uVar9 = 1;

  }

  FUN_14022e1d0(param_2,param_3,uVar3,uVar4,uVar2,uVar5,uVar1,uVar9,uVar6,uVar7,uVar8);

  return;

}





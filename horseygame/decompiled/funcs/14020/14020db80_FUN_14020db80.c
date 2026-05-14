// Address: 0x14020db80
// Ghidra name: FUN_14020db80
// ============ 0x14020db80 FUN_14020db80 (size=356) ============


undefined8 FUN_14020db80(longlong param_1,int param_2)



{

  longlong *plVar1;

  undefined4 uVar2;

  undefined8 *puVar3;

  longlong lVar4;

  char local_res10 [8];

  

  local_res10[0] = '\0';

  lVar4 = (longlong)param_2 * 0x30 + DAT_1403fd2f8;

  puVar3 = (undefined8 *)FUN_1401841a0(1,0x48);

  if (puVar3 == (undefined8 *)0x0) {

    return 0;

  }

  *(undefined8 **)(param_1 + 0x148) = puVar3;

  plVar1 = *(longlong **)(lVar4 + 8);

  *puVar3 = plVar1;

  (**(code **)(*plVar1 + 8))();

  (*(code *)**(undefined8 **)*puVar3)((undefined8 *)*puVar3,&DAT_140350598,puVar3 + 1);

  (*(code *)**(undefined8 **)*puVar3)((undefined8 *)*puVar3,&DAT_1403505a8,puVar3 + 2);

  if (DAT_1403fd2c8 != (longlong *)0x0) {

    (**(code **)(*DAT_1403fd2c8 + 0x30))(DAT_1403fd2c8,puVar3[1],puVar3 + 3);

  }

  plVar1 = (longlong *)puVar3[1];

  if (plVar1 != (longlong *)0x0) {

    (**(code **)(*plVar1 + 0x68))(plVar1,local_res10);

  }

  *(uint *)(param_1 + 0xe4) = (local_res10[0] != '\0') + 1;

  (**(code **)(*(longlong *)*puVar3 + 0x38))((longlong *)*puVar3,param_1 + 0x70);

  (**(code **)(*(longlong *)*puVar3 + 0x30))((longlong *)*puVar3,param_1 + 0x44);

  (**(code **)(*(longlong *)*puVar3 + 0x58))((longlong *)*puVar3,param_1 + 0x60);

  if (puVar3[3] != 0) {

    uVar2 = FUN_140158c10(param_1);

    FUN_140175280(uVar2,"SDL.joystick.cap.rumble",1);

    uVar2 = FUN_140158c10(param_1);

    FUN_140175280(uVar2,"SDL.joystick.cap.trigger_rumble",1);

  }

  return 1;

}





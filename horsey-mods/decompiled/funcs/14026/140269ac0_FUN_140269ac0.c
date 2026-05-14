// Address: 0x140269ac0
// Ghidra name: FUN_140269ac0
// ============ 0x140269ac0 FUN_140269ac0 (size=223) ============


undefined2 FUN_140269ac0(undefined8 *param_1,short param_2,short param_3)



{

  undefined1 uVar1;

  char cVar2;

  undefined2 uVar3;

  undefined8 *puVar4;

  

  FUN_140269370(param_3);

  FUN_1402696a0(param_2);

  if ((param_2 == 0) && (param_3 == 0)) {

    puVar4 = param_1 + 7;

    FUN_14026cf50(*param_1,puVar4);

    FUN_14026cf50(*param_1,(longlong)puVar4 + 4);

    uVar1 = 0;

  }

  else {

    puVar4 = param_1 + 7;

    FUN_140269330(*param_1,puVar4,0x74);

    FUN_140269330(*param_1,(longlong)puVar4 + 4,0x74);

    if ((param_2 == 0) && (param_3 == 0)) {

      uVar1 = 0;

    }

    else {

      uVar1 = 1;

    }

  }

  *(undefined1 *)(param_1 + 0x10) = uVar1;

  cVar2 = FUN_14026d560(param_1);

  if (cVar2 == '\0') {

    uVar3 = FUN_14012e850("Couldn\'t send rumble packet");

    return uVar3;

  }

  return 1;

}





// Address: 0x140024ac0
// Ghidra name: FUN_140024ac0
// ============ 0x140024ac0 FUN_140024ac0 (size=127) ============


undefined8 * FUN_140024ac0(undefined8 *param_1,uint param_2)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  

  *param_1 = TiXmlNode::vftable;

  puVar2 = (undefined8 *)param_1[5];

  while (puVar2 != (undefined8 *)0x0) {

    puVar1 = (undefined8 *)puVar2[0xc];

    (**(code **)*puVar2)(puVar2,1);

    puVar2 = puVar1;

  }

  FUN_140027900(param_1 + 7);

  *param_1 = TiXmlBase::vftable;

  if ((param_2 & 1) != 0) {

    FUN_1402c7088(param_1,0x70);

  }

  return param_1;

}





public void postCreate(GridContext context) throws GridServiceException
{
    // Create Service Data Element
    serviceData = this.getServiceDataSet().create("MathData");

    // Set the value of the SDE to a MathDataType instance
    mathData = new MathDataType();     serviceData.setValue(mathData);      // Set intial values of MathServiceData
    mathData.setLastOp("NONE");
    mathData.setNumOps(0);

    // Add SDE to Service Data Set
    this.getServiceDataSet().add(serviceData);
}


cmd_/home/anusha/Desktop/LDD/first_hello/Module.symvers := sed 's/\.ko$$/\.o/' /home/anusha/Desktop/LDD/first_hello/modules.order | scripts/mod/modpost -m -a  -o /home/anusha/Desktop/LDD/first_hello/Module.symvers -e -i Module.symvers   -T -

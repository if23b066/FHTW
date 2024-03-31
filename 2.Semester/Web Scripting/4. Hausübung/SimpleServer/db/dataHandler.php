<?php
include("./models/person.php");
class DataHandler
{
    public function queryPersons()
    {
        $res =  $this->getDemoData();
        return $res;
    }

    public function queryPersonById($id)
    {
        $result = array();
        foreach ($this->queryPersons() as $val) {
            if ($val[0]->id == $id) {
                array_push($result, $val);
            }
        }
        return $result;
    }

    public function queryPersonByName($name)
    {
        $result = array();
        foreach ($this->queryPersons() as $val) {
            if ($val[0]->lastname == $name) {
                array_push($result, $val);
            }
        }
        return $result;
    }

public function queryPersonInfoByName($name)
{
    $result = array();
    foreach ($this->queryPersons() as $val) {
        if ($val[0]->lastname == $name) {
            array_push($result, [
                "firstname" => $val[0]->firstname,
                "email" => $val[0]->email,
            ]);
        }
    }
    return $result;
}

public function queryPersonByPosition($position)
{
    $result = array();
    foreach ($this->queryPersons() as $val) {
        if ($val[0]->position == $position) {
            array_push($result, $val);
        }
    }
    return $result;
}

    private static function getDemoData()
    {
        $demodata = [
            [new Person(1, "Jane", "Doe", "jane.doe@fhtw.at", 1234567, "Central IT", "Software Developer")],
            [new Person(2, "John", "Doe", "john.doe@fhtw.at", 34345654, "Help Desk", "Support Technician")],
            [new Person(3, "baby", "Doe", "baby.doe@fhtw.at", 54545455, "Management", "HR Manager")],
            [new Person(4, "Mike", "Smith", "mike.smith@fhtw.at", 343477778, "Faculty", "Professor")],
            [new Person(5, "James", "Smith", "james.smith@fhtw.at", 43532342, "Service Desk", "Support Technician")],
            [new Person(6, "Kanye", "Smith", "kanye.smith@fhtw.at", 187187187, "Helpers", "Janitor")],
        ];
        return $demodata;
    }
}

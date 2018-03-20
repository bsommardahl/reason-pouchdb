let db = connect("orders");

/* db */
/* |> PouchDBConnection.info */
/* |> Js.Promise.then_(info => { */
/*      Js.log(info##db_name); */
/*      Js.Promise.resolve(); */
/*    }); */
/* db */
/* |> PouchDBConnection.put({"_id": "test"}) */
/* |> Js.Promise.then_(response => { */
/*      Js.log(response##ok); */
/*      Js.Promise.resolve(); */
/*    }); */

let query = FindRequest.query(~selector: {"test": "foo"});

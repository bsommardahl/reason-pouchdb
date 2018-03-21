let _ = {
  open Pouchdb;
  let dbUrl = "http://localhost:5984/testdb";
  let db = ref(pouchdb(dbUrl));
  Js.log(db^);
  Js.Promise.(
    destroy(db^)
    |> then_(() => {
         resolve(pouchdb(dbUrl));
       })
    |> then_(newDb => {
         db := newDb;
         resolve();
       })
  );
};
/*
 db |> PouchDBConnection.post({"name": "testing"}) |> ignore; */
/*
 let name = string_of_float(Js.Date.now());

 db
 |> PouchDBConnection.post({"name": name})
 |> Js.Promise.then_((_: RevResponse.t) => {
      db
      |> PouchDBConnection.query(
           FindRequest.query(~selector={"name": name}, ()),
         )
      |> Js.Promise.then_(response => {
           let docs = response##docs;
           Js.log(docs[0]##name);
           db |> PouchDBConnection.closeConnection |> ignore;
           Js.Promise.resolve();
         })
      |> Js.Promise.catch(err => Js.Promise.resolve(Js.log(err)))
      |> ignore;
      Js.Promise.resolve();
    })
 |> ignore; */
